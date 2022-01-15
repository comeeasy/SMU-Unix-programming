#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int sum = 0;

	for(int i=1; i<argc; ++i) {
		printf("%s ", argv[i]);
		sum += atoi(argv[i]);
	}
	printf("\n");
	printf("sum=%d\n", sum);
		
  exit(0);
}
