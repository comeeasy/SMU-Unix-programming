#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/utsname.h>

struct utsname buf;

int main(int argc, char *argv[]) {
  int n;	
	const char *format = "%s, %s, %s, %s, %s\n";

	if ((n = uname(&buf)) == -1) {
		perror("utsname");
		exit(1);
	}

	printf(format,
			buf.sysname,
			buf.nodename,
			buf.release,
			buf.version,
			buf.machine
	);

	return 0;
}
