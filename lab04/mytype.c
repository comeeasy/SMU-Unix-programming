#include <stdio.h> // perror
#include <errno.h> // perror
#include <stdlib.h> // exit
#include <sys/stat.h> // S_IS* MACRO, lstat, mode_t


int mytype(const char *path) {
	struct stat status;
	mode_t mode;
	char ftype;

	if (lstat(path, &status) == -1) {
		perror("lstat");
		exit(1);
	}

	mode = status.st_mode;
	if (S_ISREG(mode)) {
		ftype = '-';
	} else if (S_ISDIR(mode)) {
		ftype = 'd';
	}else if (S_ISCHR(mode)) {
		ftype = 'c';
	}else if (S_ISBLK(mode)) {
		ftype = 'b';
	}else if (S_ISFIFO(mode)) {
		ftype = 'f';
	}else if (S_ISLNK(mode)) {
		ftype = 'l';
	}

	fprintf(stdout, "%c %s\n", ftype, path);
	return 0;
}

int main(int argc, char *argv[]) {
  for(int i=1; i<argc; ++i) {
		mytype(argv[i]);
	}

  return 0;
}
