#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd;
	int n;

	char c = *argv[2];

	if ((fd = open(argv[1], O_RDONLY)) == -1) {
		perror("open");
		exit(1);
	}

	int count = 0;
	char buf;
	while((n = read(fd, &buf, 1)) == 1) {
		if(buf == c) 
			count++;
	}
	
	printf("%d\n", count);

	close(fd);
  return 0;
}
