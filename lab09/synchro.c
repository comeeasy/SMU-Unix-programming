#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int shared_i = 0;
pthread_mutex_t lock;

void *thread_function1(void *arg) {
	static int ret = 1;
	
	for (int i=0; i<1000; ++i) {
		for (int j=0; j<1000; ++j) {
			pthread_mutex_lock(&lock);
			shared_i++;
			pthread_mutex_unlock(&lock);
		}
	}

	printf("thread_function1 exit: %d\n", ret);
	pthread_exit((void *) &ret);
}

void *thread_function2(void *arg) {
	static int ret = 2;
	
	for (int i=0; i<1000; ++i) {
		for (int j=0; j<1000; ++j) {
			pthread_mutex_lock(&lock);
			shared_i++;
			pthread_mutex_unlock(&lock);
		}
	}

	printf("thread_function2 exit: %d\n", ret);
	pthread_exit((void *) &ret);
}


int main() {
	int err;
	pthread_t tid1, tid2;
	int *ret1, *ret2;

	err = pthread_create(&tid1, NULL, thread_function1, NULL);
	if (err != 0) 
		exit(1);

	err = pthread_create(&tid2, NULL, thread_function2, NULL);
	if (err != 0) 
		exit(1);

	err = pthread_join(tid1, (void *) &ret1);
	if (err != 0) 
		exit(1);
	printf("thread_function1 join: %d\n", *ret1);

	err = pthread_join(tid2, (void *) &ret2);
	if (err != 0) 
		exit(1);
	printf("thread_function2 join: %d\n", *ret2);

	printf("shared_i = %d\n", shared_i);

	exit(0);
}
