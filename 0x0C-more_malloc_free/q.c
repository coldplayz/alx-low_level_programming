#include "main.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	//int i;
	char *res;
	char *s2 = "66533689987223998456872";
	char *s1 = "225649980007";

	res = rev_mult_rev(s1, s2);

	/*
	for (i = 0; i < 4; i++)
	{
		printf("res[%d]: %s\n", i, res[i]);
	}
	*/
	printf("Product of %s and %s: %s\n", s1, s2, res);

	free(res);

	return (0);
}
