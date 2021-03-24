#include <stdlib.h> // gestión de memoria dinámica
#include <errno.h> // macros que presentan un informe de error
#include <stdio.h>
#include <string.h>
#include <math.h>

#define LIMIT 50

struct fibo_entry
{                          /* Definition of each table entry */
  int n;
  unsigned long long int lli;       /* 64-bit integer */
  char *str;
};

void
panic (char *m)
{
  fprintf (stderr, "%s\n", m); //  stderr=Error output
  exit (0);
}

void 
free_memory(struct fibo_entry *table, int size)
{

///* Your code starts here */
   
  for (int i = 0; i < size; ++i)
    
    {  
    
    free(table[i].str);

    }

  free(table);   

///* Your code ends here */

}

int
main (int argc, char *argv[]) //argc=contains the inputs/num of arguments / argv[]=arrays of pointers

{
  int n;
  int i;
  struct fibo_entry *fibo_table;


  if (argc != 2)
    panic ("wrong parameters");

  n = atoi (argv[1]);         //atoi =converts the string argument str to an integer (type int).
  if (n < 2)
    panic ("n too small");
  if (n > LIMIT)
    panic ("n too big");


/* Your code starts here */


//dinamic memory
fibo_table = (struct fibo_entry*) malloc (( LIMIT + 1 ) * sizeof(struct fibo_entry));

if(fibo_table == NULL )
  panic("malloc");

//set values input
fibo_table[0].n =0;

fibo_table[0].lli =0;
fibo_table[0].str ="0";

fibo_table[1].lli =1;
fibo_table[1].str ="1";


int n1=0,n2=1,n3=0;
  
//counter
for (i=0;i<=n;i++)

    {

   fibo_table[i].n =  i;
  
    }

//fibo formula
for (i=2;i<=n;i++)
    {
    
    int j;

    n3= n1+n2;
    fibo_table[i].lli = n3;

    j = log10(fibo_table[i].lli) + 1;

    fibo_table[i].str = (char*) malloc ( (j + 1 ) * sizeof(char) );

      if (fibo_table[i].str == NULL)
        panic ("malloc");

    sprintf(fibo_table[i].str, "%d", n3);

    n1=n2; 
    n2=n3;

    }

/* Your code ends here */

  for (i = 0; i <= n; i++)          //imprime
    {
      printf ("%d %llu %s\n", fibo_table[i].n, fibo_table[i].lli,
              fibo_table[i].str);
    }

  free_memory(fibo_table, n);

  printf ("%d %llu %s\n", fibo_table[4].n, fibo_table[4].lli, fibo_table[4].str);

  return 0;
}
