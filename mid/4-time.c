#include <time.h>
#include <stdio.h>

int main(void) {
  time_t t;
	struct tm tm1;

	time(&t);

	printf("calendar time\t%ld\n", t);
	printf("string time\t%s", ctime(&t));

	tm1 = *localtime(&t);
	printf("local time\t%d %d %d %d %d %d %d %d %d\n", 
			tm1.tm_sec,
			tm1.tm_min,
			tm1.tm_hour,
			tm1.tm_mday,
			tm1.tm_mon,
			tm1.tm_year,
			tm1.tm_wday,
			tm1.tm_yday,
			tm1.tm_isdst);

	const char* format = "%G %B %d %P %l %M %S";
	char buf[100];
	strftime(buf, 100, format, &tm1);
	printf("fstring time\t%s\n", buf);

  return (0);
}
