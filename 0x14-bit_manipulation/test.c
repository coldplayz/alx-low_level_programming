#include <stdio.h>
#include "main.h"

int main(void)
{
	unsigned long int i, mask, n;

	mask = (unsigned long int)1 << 32;
	printf("%lu\n", mask);
	printf("ui: %lu\n", sizeof(unsigned long int));

	return (0);
}
