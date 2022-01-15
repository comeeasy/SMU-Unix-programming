#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  struct passwd *pd;

	const char *format = "%s, %d, %d, %s, %s, %s\n";

  if((pd = getpwnam(argv[1])) == NULL) {
		fprintf(stderr, "%s: unknown user\n", argv[1]);
		exit(1);
  }

	printf(format,
			pd->pw_name,
			pd->pw_uid,
			pd->pw_gid,
			pd->pw_gecos,
			pd->pw_dir,
			pd->pw_shell
	);


	return 0;
}
