#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
		fprintf(stderr, "usage: %s file1 file2\n", argv[0]);
		exit(1);
	}

	if (rename(argv[1] ,argv[2]) == -1) {
		perror("rename");
		exit(1);
	}

  return 0;
}
