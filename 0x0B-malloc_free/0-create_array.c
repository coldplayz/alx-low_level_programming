#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array of chars,
 * and initializes it with a specific char.
 * @size: the size of the array to initilize.
 * @c: the character to initialize the array with.
 *
 * Return: a pointer to the array, or NULL if it fails.
 */
char *create_array(unsigned int size, char c)
{
	char *ptc;
	unsigned int i;

	if (size == 0)
	{
		return (NULL);
	}

	ptc = malloc(size * sizeof(char));
	if (ptc == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (i < size)
	{
		ptc[i] = c;
		i++;
	}

	return (ptc);
}
