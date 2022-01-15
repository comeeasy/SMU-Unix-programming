#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

int main() {
	const char *hello = "hello world\n";
	int fd;
	int n;

	//if ((fd = open("hello_world", O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1) {
	//	perror("open");
	//	exit(1);
	//}

	//if ((n = write(STDOUT_FILENO, (void *)hello, 12)) == -1) {
	//	perror("write1");
	//	exit(1);
	//}

	//if ((n = write(fd, (void *)hello, 12)) == -1) {
	//	perror("write2");
	//	exit(1);
	//}

	struct stat statBuf;
	
	if ((n = fstat(fd, &statBuf)) == -1) {
		perror("stat");
		exit(1);
	} 

	printf("st_ino : %ld = inode number\n", statBuf.st_ino);
	printf("st_uid : %ld = user id of owner\n", statBuf.st_uid);
	printf("st_gid : %ld = group id of owner\n", statBuf.st_gid);
	printf("st_mode : %4o = type and mode\n", statBuf.st_mode);
	printf("st_blksize : %ld = block size\n", statBuf.st_blksize);
	printf("st_size : %ld = file size in bytes\n", statBuf.st_size);
	printf("st_atime : %ld = last access time\n", statBuf.st_atime);
	printf("st_mtime : %ld = last modified time\n", statBuf.st_mtime);
	printf("st_ctime : %ld = last changed time\n", statBuf.st_ctime);

	struct tm myGmtime;
	struct tm myLocaltime;

	myGmtime = *gmtime(&(statBuf.st_atime));
	myLocaltime = *localtime(&(statBuf.st_atime));

	printf("asctime gmtime : %s", asctime(&myGmtime));
	printf("asctime loctime: %s", asctime(&myLocaltime));
	printf("ctime   gmtime : %s", ctime(&statBuf.st_atime));
	printf("mktime  gmtime : %ld\n", mktime(&myGmtime));
	printf("mktime  loctime: %ld\n", mktime(&myLocaltime));

	return 0;
}
