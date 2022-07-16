#include <stdio.h>

int main(void)
{
  int n;
  int a[5];
  int *p;

  a[2] = 1024;
  printf("a address: %p\n", a);
  printf("a[2] address: %p\n", &a[2]);
  printf("p address before n: %p\n", p);
  p = &n;
  /*
   * write your line of code here...
   * Remember:
   * - you are not allowed to use a
   * - you are not allowed to modify p
   * - only one statement
   * - you are not allowed to code anything else than this line of code
   */
  printf("n address: %p\n", &n);
  printf("p address after n: %p\n", p);
  *(p + 5) = 98;
  printf("p address after dereferencing: %p\n", p);
  /* ...so that this prints 98\n */
  printf("a[2] = %d\n", a[2]);
  return (0);
}
