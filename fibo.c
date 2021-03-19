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
/* Your code starts here */
    free(&table[size]);   
   
/* Your code ends here */
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

fibo_table = malloc(sizeof(struct fibo_entry));

fibo_table[LIMIT].lli = (unsigned long long)malloc(sizeof(unsigned long long) * log10(argc));

fibo_table[LIMIT].str = (char*) malloc (sizeof(char) * log10(fibo_table->lli));
 
int n1=0,n2=1,n3=0;
  
  //n counter
for (i=0;i<=LIMIT;i++)

    {

   fibo_table[i].n = fibo_table[i].n  + i;

    }

  //fibo formula
 
  
for (i=2;i<=LIMIT;i++)
    {

    n3= n1+n2;
    fibo_table[i].lli = n3;
    sprintf(fibo_table->str,"%d", fibo_table->n);
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

  return 0;
}
