#include <unistd.h>
#include <wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
		int pid;

		printf("parent: fork...\n");

		pid = fork();

		if(pid < 0) {
			perror("fork");
			exit(1);
		} else if(pid == 0) {
			printf("child: exec...\n");
			execvp(argv[1], &argv[1]);
			printf("child: exit...\n");
			exit(0);
		} else {
			printf("parent: wait...\n");
			wait(NULL);
			printf("parent: exit...\n");
		exit(0);
	}
}
