#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int glob = 6;

int main(void) {
  pid_t pid;
	int loc = 88;

	printf("before fork\n");
	pid = fork();
	if (pid < 0) {
		perror("fork");
		exit(1);
	} else if (pid == 0) {
		glob++;
		loc++;
	} else {
		sleep(2);
	}
	printf("pid=%d, glob=%d, loc=%d\n", getpid(), glob, loc);
  
	return 0;
}
