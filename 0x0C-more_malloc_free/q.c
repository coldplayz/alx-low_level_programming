#include "main.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	char *res;
	char *s1 = "998";
	char *s2 = "200000000";

	//res = add_rev_str(s1, s2, 23);
	//rev_string(res);
	
	res = rev_add_rev(s1, s2);

	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("res: %s\n", res);
	free(res);

	return (0);
}
