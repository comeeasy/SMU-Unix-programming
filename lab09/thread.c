#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void print_ids(const char *s) {
	pid_t pid = getpid();
	pthread_t tid = pthread_self();
	printf("%s: 	pid=%u, 	tid=%x\n", s,
			(unsigned int) pid, (unsigned int) tid);
}

void *thread_function(void *arg) {
	print_ids("new thread");
	return (void *)0;
}

int main() {
	pthread_t tid;
	int error;

	if ((error = pthread_create(
					&tid, NULL, thread_function, NULL)) != 0) {
		fprintf(stderr, "%d: can't create thread\n", error);
	}

	print_ids("main thread");
	sleep(1);

	return 0;
}
