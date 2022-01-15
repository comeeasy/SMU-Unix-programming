#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>


void parentHandler(int signo) {
	if (signo == SIGUSR1) {
		printf("parent...\n");
	} else if (signo == SIGALRM) {
		exit(0);
	}
}

void childHandler(int signo) {
	if (signo == SIGUSR1) {
		printf("child...\n");
	}  else if (signo == SIGALRM) {
		exit(0);
	}
}


int main(void) {
	int pid;


	pid = fork();
	if (pid < 0) {
		perror("fork");
		exit(1);
	} else if (pid == 0) { //child proess
		if (signal(SIGUSR1, childHandler) == SIG_ERR) {
			perror("signal");
			exit(1);
		}
		if (signal(SIGALRM, childHandler) == SIG_ERR) {
			perror("signal");
			exit(1);
		}

		alarm(10);
		for (;;) {
			sleep(1);
			kill(getppid(), SIGUSR1);
			pause();
		}
	} else { // parent process
		if (signal(SIGUSR1, parentHandler) == SIG_ERR) {
			perror("signal");
			exit(1);
		}
		if (signal(SIGALRM, parentHandler) == SIG_ERR) {
			perror("signal");
			exit(1);
		}

		alarm(10);
		for (;;) {
			pause();
			sleep(1);
			kill(pid, SIGUSR1);
		}
	}

	exit(0);
}
