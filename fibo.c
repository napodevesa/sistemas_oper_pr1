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

fibo_table->lli = (unsigned long long)malloc(sizeof(unsigned long long));
fibo_table->str = malloc(sizeof(char)*1024);
 

fibo_table[1].lli = 1;

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
    n1=n2; 
    n2=n3;

    }
    
    //sprintf(fibo_table->str, "%d", n3);


/*
for (i=0;i<=3;i++)
    {
    n3= n1+n2;
    fibo_table[i].str = (char)n3;
    //sprintf(fibo_table->str, "%d", n3);
   // puts(fibo_table->str);
    n1=n2; 
    n2=n3;

    }

*/

/*
fibo_table[0].lli = 1;
fibo_table[1].lli = 1;
fibo_table[2].lli = 2;
fibo_table[3].lli = 3;
fibo_table[4].lli = 5;
fibo_table[5].lli = 8;
fibo_table[6].lli = 13;


*/
fibo_table[0].str = "0";
fibo_table[1].str = "1";
fibo_table[2].str = "1";
fibo_table[3].str = "2";
fibo_table[4].str = "3";
fibo_table[5].str = "5";
fibo_table[6].str = "8";
fibo_table[7].str= "13";



/* Your code ends here */

  for (i = 0; i <= n; i++)          //imprime
    {
      printf ("%d %llu %s\n", fibo_table[i].n, fibo_table[i].lli,
              fibo_table[i].str);
    }

  free_memory(fibo_table, n);

  return 0;
}
