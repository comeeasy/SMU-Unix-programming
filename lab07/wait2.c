#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  pid_t pid;

	pid = fork();
	if (pid < 0) {
		perror("fork");
		exit(1);
	} else if (pid == 0) {
		printf("child=%d\n", getpid());
	} else {
		printf("parent=%d\n", getpid());
		wait(NULL);
		sleep(60);
	}

	return 0;
}
