#include <time.h>
#include <stdio.h>

int main() {

// ===============================
 /* usage of time function and time_t datatype */

	time_t t1;
	time_t t2;

	time(&t1);
	time(&t2);

	printf("t1: %ld\n", t1);
	printf("t2: %ld\n", t2);

//==================================
	/* usage of gmtime, localtime function			*/
	/* converting time_t time to struct tm time */

	struct tm tm1;
	struct tm tm2;

	tm1 = *gmtime(&t2);
	tm2 = *localtime(&t2);

	/* struct tm */
	/*
	struct tm {
		int tm_sec;
		int tm_min;
		int tm_hour;
		int tm_mday;
		int tm_mon;
		int tm_year;
		int tm_wday; //mon, tues wedsn, ... sun -> 0, 1, 2,...,6
		int tm_yday; 1 -365;
		int tm_isdst; [-1 , 0 , 1]
	}

	*/

//===================================
	/* asctime struct tm -> string  */
	/* ctime   time_t    -> string  */\

	char *str1 = asctime(&tm2);
	char *str2 = ctime(&t2);

	printf("asctime: %s\n", str1);
	printf("ctime  : %s\n", str2);

//==================================
	/* strftime struct tm -> str format */
	char buf[1024];
	const char *myFormat = "%Y-%m-%d-%H-%M-%S\n";

	size_t n = strftime(buf, 100, myFormat, &tm2);
	printf("size_t n: %ld\n", n);
	printf("strftime: %s", buf);
	
	return 0;
}
