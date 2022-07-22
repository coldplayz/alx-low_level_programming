#include <stdio.h>
#include "main.h"

int main(int argc, char **argv)
{
	int print_sum(char *n1, char *n2);

	print_sum(argv[1], argv[2]);
	return (0);
}

int print_sum(char *n1, char *n2)
{
	printf("%d\n", (*n1 + *n2));
}
