#include <string.h>
#include <stdlib.h>
#include "3-calc.h"
#include "function_pointers.h"
#include <stdio.h>


/**
 * main - driver function to perform any of
 * a set number of operations on integers, and print the result
 * @ac: the argument count
 * @av: an array of pointers to strings that represent the arguments
 *
 * Return: always 0
 */
int main(int ac, char *av[])
{
	int (*ptf)(int, int);
	int res;

	if (ac != 4)
	{
		printf("Error\n");
		exit(98);
	}

	ptf = get_op_func(av[2]);

	if (ptf == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	if (((ptf == &op_div) || (ptf == &op_mod)) && (strcmp(av[3], "0") == 0))
	{
		printf("Error\n");
		exit(100);
	}

	res = ptf(atoi(av[1]), atoi(av[3]));
	printf("%d\n", res);
	return (0);
}
