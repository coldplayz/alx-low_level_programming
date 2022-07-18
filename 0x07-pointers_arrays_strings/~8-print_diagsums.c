#include <stdio.h>
#include "main.h"

/**
 * print_diagsums - prints the sum of the two diagonals of a square matrix of integers
 * @a: a square matrix (2D array)
 * @size: square dimensions of the matrix
 */
void print_diagsums(int *a, int size)
{
	int i, j, k = (size - 1), fslash_sum = 0, bslash_sum = 0;

	for (i = 0; i < size; i++)
	{
		fslash_sum += a[i][i];
	}

	for (j = 0; j < size; j++)
	{
		bslash_sum += a[j][k];
		k--;
	}

	printf("%d, %d\n", fslash_sum, bslash_sum);
}
