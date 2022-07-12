#include "main.h"

/**
 * swap_int - swwaps the values of integers
 * @a: pointer to integer
 * @b: pointer to integer
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
