#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	int fd[2], pid;

	if (argc != 3) {
		fprintf(stderr, "usage: pip3 com1 com2\n");
		exit(1);
	}

	if (pipe(fd) == -1) {
		perror("pipe");
		exit(1);
	}

	if ((pid = fork()) == -1) {
		perror("fork");
		exit(1);
	} else if (pid == 0) { // child
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		system(argv[1]);
		exit(0);
	} else {							// parent
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		system(argv[2]);
		exit(0);
	}
}
