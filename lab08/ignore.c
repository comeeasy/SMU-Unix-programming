#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(void) {
  int i;

	if (signal(SIGINT, SIG_IGN) == SIG_ERR) {
		perror("signal");
		exit(1);
	}

	for (i=0; i<20; ++i) {
		printf("sleeping for 1 second...\n");
		sleep(1);
	}

  return 0;
}
