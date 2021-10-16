#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>


int myugid(const char *path) {
	struct stat status;
	uid_t uid;
	gid_t gid;

	if (lstat(path, &status) == -1) {
		perror("lstat");
		exit(1);
	}
	
	uid = status.st_uid;
	gid = status.st_gid;

	fprintf(stdout, "%5d %5d %s\n", uid, gid, path);
	return 0;
}

int main(int argc, char *argv[]) {
  for(int i=1; i<argc; ++i) {
		myugid(argv[i]);
	}

  return 0;
}
