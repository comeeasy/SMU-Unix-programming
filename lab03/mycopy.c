#include <unistd.h> // write, close
#include <fcntl.h>  // FD MACRO, flags
#include <errno.h>  // error list(perror)
#include <stdio.h>  // printf, perror
#include <stdlib.h> // exit

#define BUFSIZE 524288

int main(int argc, char *argv[]) {
  int fd_read, fd_write;
	
	// open file to read
	if((fd_read = open(argv[1], O_RDONLY)) == -1) {
		perror("fd_read");
		exit(1);
	}

	// open file to write
	if((fd_write = open(argv[2], O_CREAT | O_WRONLY | O_EXCL, 0644)) == -1) {
		perror("fd_write");
		exit(1);
	}
	
	int n;
	char buf[BUFSIZE];

	while(1) {
		// read
		n = read(fd_read, buf, BUFSIZE);
		if(n == 0) 
			break;
		else if(n == -1) {
			perror("read");
			exit(1);
		}

		// write
		n = write(fd_write, buf, BUFSIZE);
		if(n != BUFSIZE) {
			perror("write");
			exit(1);
		}
	}

	int i = BUFSIZE;
	printf("BUFSIZE: %d\n", i);

	close(fd_read);
	close(fd_write);
  exit(0);
}
