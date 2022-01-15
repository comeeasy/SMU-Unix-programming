#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/times.h>

struct tms buf;

int main(int argc, char *argv[]) {
  int pid;
	unsigned int start_time;

	printf("parent: fork...\n");
	pid = fork();
	if (pid < 0) {
		perror("fork");
		exit(1); 
	} else if (pid == 0) {
		printf("child exec...\n");
		execvp(argv[1], &argv[1]);
		exit(0);
	} else {
		start_time  = times(NULL);
		printf("parent: wait...\n");
		wait(NULL);
		printf("parent: exit...\n");
		printf("real: %.3f sec\n", (times(&buf) - start_time) / (float) sysconf(_SC_CLK_TCK));
		printf("user: %.3f sec\n", buf.tms_cutime / (float) sysconf(_SC_CLK_TCK));
		printf("sys : %.3f sec\n", buf.tms_cstime / (float) sysconf(_SC_CLK_TCK));
		exit(0);
	}
}
