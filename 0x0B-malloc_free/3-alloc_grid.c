#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - creates a pointer to a 2 dimensional array of integers.
 * @width: the number of rows of the matrix
 * @height: the number of columns of the matrix
 *
 * Return: a pointer to a 2 dimensional array of integers.
 */
int **alloc_grid(int width, int height)
{
	int i, j;
	int **ptp;

	if ((width <= 0) || (height <= 0))
	{
		return (NULL);
	}

	ptp = malloc((height) * sizeof(int *));
	for (i = 0; i < height; i++)
	{
		ptp[i] = malloc(width * sizeof(int));
		if (ptp[i] == NULL)
		{
			return (NULL);
		}
	}
	if (ptp == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			ptp[i][j] = 0;
		}
	}

	for (i = 0; i < height; i++)
	{
		free(ptp[i]);
	}
	free(ptp);

	return (ptp);
}
