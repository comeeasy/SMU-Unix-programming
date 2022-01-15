#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

void second(void)
{
  printf("second: entering...\n");
  longjmp(buf, 1);
  printf("second: exiting...\n");
}

void first(void)
{
  printf("first: entering...\n");
  second();
  printf("first: exiting...\n");
}

int main()
{
  printf("main: entering...\n");
  if (setjmp(buf) == 0)
    first();
  printf("main: exiting...\n");

  return 0;
}
