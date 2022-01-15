#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


void alarm_handler(int signo) {
	if (signo == SIGALRM) {
		printf("running...\n");
	}
}

int main(int argc, char *argv[]) {
  if (signal(SIGALRM, alarm_handler) == SIG_ERR) {
		perror("signal");
		exit(1);
	}
	
	int time = atoi(argv[1]);
	for(int i=0; i<time; ++i) {
		alarm(1);
		sleep(1);
	}

  return 0;
}
