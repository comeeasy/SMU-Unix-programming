#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i;

	for (i=0; i<20; ++i) {
		printf("sleeping for 1 second...\n");
		sleep(1);
	}

  return 0;
}
