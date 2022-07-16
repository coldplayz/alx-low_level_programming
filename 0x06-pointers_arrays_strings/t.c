#include <stdio.h>
#include "main.h"

int main()
{
	char c = 'a';
	printf("%c\n", c);
	rot13_map(&c);
	printf("%c\n", c);
	return 0;
}
