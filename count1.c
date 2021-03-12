#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long long k = 0;

void
foo (int signo)
{
}

void
sigterm (int signo)
{
  printf ("%lld\n", k);
  exit (0);
}

int
main (int argc, char *argv[])
{
  sigset_t mask;

  signal (SIGTERM, sigterm);
  signal (SIGUSR1, foo);
  sigemptyset(&mask);

  sigsuspend(&mask);

  for (k = 0; (1 == 1); k++);

  return 0;
}
