#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int fd, n;
	char c;

	if((fd = open(argv[1], O_RDONLY)) == -1) {
		perror("open");
		exit(1);
	}

	while(1) {
		n = read(fd, &c, 1);

		if(n == 0) // read syscall returns 0 if EOF 
			break;
		else if(n == -1){		 // unexpected case 
			perror("read");
			exit(1);
		}

		printf("%c", c); // print character
	}

	close(fd);
  exit(0);
}
