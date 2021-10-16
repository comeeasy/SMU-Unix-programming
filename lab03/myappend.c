#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	int fd, length, i, n;

	if( (fd = open(argv[1], O_WRONLY | O_APPEND)) == -1 ) {
		perror("open");
		exit(1);
	}
  
	length = atoi(argv[3]);
	for(i=0; i<length; ++i) {
		n = write(fd, argv[2], 1);
		if(n != 1) {
			perror("write");
			exit(1);
		}
	}

	close(fd);
  exit(0);
}
