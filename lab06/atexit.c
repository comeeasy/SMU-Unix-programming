#include <stdio.h>
#include <stdlib.h>


int exitno;

void print_exitno() {
	printf("exit=%d\n", exitno);
}

int main(int argc, char *argv[]) {
	exitno = atoi(argv[1]);
	atexit(print_exitno);

	exit(exitno);
}
