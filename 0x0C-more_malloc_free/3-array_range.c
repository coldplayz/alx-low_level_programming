#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers.
 * @min: an int representing the lower limit of the range
 * @max: an int representing the upper limit of the range
 *
 * Return: the pointer to the newly created array
 */
int *array_range(int min, int max)
{
	int i, *pti;

	if (min > max)
	{
		return (NULL);
	}

	pti = malloc(sizeof(int) * ((max - min) + 1));
	if (pti == NULL)
	{
		return (NULL);
	}

	for (i = 0; i <= (max - min); i++)
	{
		pti[i] = min + i;
	}

	return (pti);
}
