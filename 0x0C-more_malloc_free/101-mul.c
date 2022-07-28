#include <stdlib.h>
#include "main.h"

/**
 * main - myltiplies two positive numbers
 * @ac: number of arguments passed to the program
 * @av: array of the arguments as strings
 *
 * Return: always 0
 */
int main(int ac, char **av)
{
	int i, j;

	if (ac != 3)
	{
		_puts("Error");
		exit(98);
	}
	for (i = 1; i < ac; i++)
	{
		for (j = 0; *(av[i] + j); j++)
		{
			if ((*(av[i] + j) < 48) || (*(av[i] + j) > 57))
			{
				_puts("Error");
				exit(98);
			}
		}
	}
	prod = atoi(av[1]) * atoi([2]);

	return (0);
}

