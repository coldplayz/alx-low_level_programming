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
	int i, j, len;
	int **ptp, *pti;

	if ((width <= 0) || (height <= 0))
	{
		return (NULL);
	}

	len = sizeof(int *) * height + sizeof(int) * width * height;
	ptp = malloc(len);
	if (ptp == NULL)
	{
		return (NULL);
	}

	pti = (int *)(ptp + height);
	for (i = 0; i < height; i++)
	{
		ptp[i] = (pti + width * i);
	}

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			ptp[i][j] = 0;
		}
	}

	return (ptp);
}
