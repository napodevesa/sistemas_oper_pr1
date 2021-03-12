#include <stdlib.h>
#include <errno.h>
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
  fprintf (stderr, "%s\n", m);
  exit (0);
}

void 
free_memory(struct fibo_entry *table, int size)
{
/* Your code starts here */


/* Your code ends here */
}

int
main (int argc, char *argv[])
{
  int n;
  int i;
  struct fibo_entry *fibo_table;

  if (argc != 2)
    panic ("wrong parameters");

  n = atoi (argv[1]);
  if (n < 2)
    panic ("n too small");
  if (n > LIMIT)
    panic ("n too big");

/* Your code starts here */


/* Your code ends here */

  for (i = 0; i <= n; i++)
    {
      printf ("%d %llu %s\n", fibo_table[i].n, fibo_table[i].lli,
              fibo_table[i].str);
    }

  free_memory(fibo_table, n);

  return 0;
}
