#include <stdio.h>
#include "main.h"

int main(void)
{
	char c[] = "1234";
	char *p;

	p = &c;
	p[2] = '7';
	printf("size of c: %lu\n", sizeof(c));
	printf("size of p: %lu\n", sizeof(p));
	printf("c[2]: %c\n", c[2]);

	return (0);
}
