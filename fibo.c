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
  
      free(table);
    
/* Your code ends here */
}

int
main (int argc, char *argv[]) //argc=contains the inputs/num of arguments / argc=arrays of pointers

{
  int n;
  int i;
  struct fibo_entry *fibo_table;

  if (argc != 2)
    panic ("wrong parameters");

  n = atoi (argv[1]);         //atoi =c onverts the string argument str to an integer (type int).
  if (n < 2)
    panic ("n too small");
  if (n > LIMIT)
    panic ("n too big");

/* Your code starts here */
    
    int t1 = 0, t2 = 1, nextTerm;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");

   // i = malloc(sizeof(int));

    for (i = 1; i <= n; ++i) {
        nextTerm = t1 + t2;
        fibo_table[i].lli = nextTerm;
        t1 = t2;
        t2 = nextTerm;
        
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
