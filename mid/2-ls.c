#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	struct stat statBuf;
	int n;
	char type;

  for(int i=1; i<argc; ++i) {
		if ((n = lstat(argv[i], &statBuf) != -1)) {
			if(S_ISREG(statBuf.st_mode))				type = '-';
			else if(S_ISDIR(statBuf.st_mode)) 	type = 'd';
			else if(S_ISCHR(statBuf.st_mode)) 	type = 'c';
			else if(S_ISBLK(statBuf.st_mode)) 	type = 'b';
			else if(S_ISFIFO(statBuf.st_mode)) 	type = 'p';
			else if(S_ISLNK(statBuf.st_mode)) 	type = 'l';
			else if(S_ISSOCK(statBuf.st_mode)) 	type = 's';


			printf("%c %05o %4d %4d %8ld %s\n", 
					type,
					statBuf.st_mode,
					statBuf.st_uid,
					statBuf.st_gid,
					statBuf.st_size,
					argv[i]);
		}	else {
			perror("lstat");
			exit(1);
		}
	}	

  return 0;
}
