#include <time.h>

int main(void) {
  time_t t;
	char *buf;

	if ((t = time(&t)) == -1) {
		perror("time");
		exit(1);
	}
	buf = ctime(&t);
	
	printf("%lu\n", t);
	printf("%s", buf);

	return 0;
}
