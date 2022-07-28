#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - allocates memory using malloc
 * @b: the amount of bytes to allocate
 *
 * Return: a pointer to the allocated memory,
 * or an exit status of 98 if malloc fails
 */
void *malloc_checked(unsigned int b)
{
	void *ptv;

	ptv = malloc(b);
	if (ptv == NULL)
	{
		exit(98);
	}

	return (ptv);
}
