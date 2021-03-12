#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

  for (k = 0; (1 == 1); k++)
	usleep(1000); /* Wait for 0.001 seconds */

  return 0;
}
