#include <stdio.h> // perror, fprintf
#include <errno.h> // perror
#include <stdlib.h> // exit
#include <sys/stat.h> // lstat,struct stat, mode_t


int mymode(const char* path) {
	struct stat status;
	mode_t mode;

	if (lstat(path, &status) == -1) {
		perror("lstat");
		exit(1);
	}

	mode = status.st_mode & 07777;
	fprintf(stdout, "%05o %s\n", mode, path);
	return 0;
} 


int main(int argc, char *argv[]) {
  for(int i=1; i<argc; ++i) {
		mymode(argv[i]);
	}

  return 0;
}
