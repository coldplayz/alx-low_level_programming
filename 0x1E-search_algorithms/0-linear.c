#include "search_algos.h"


/**
 * linear_search - searches for a value in
 * an array of integers using the Linear search algorithm.
 * @array: pointer to the first element of the array to search in.
 * @size: number of elements in array.
 * @value: the value to search for.
 *
 * Return: the first index where value is
 * located, or -1 if not present in array or array is NULL.
 */
int linear_search(int *array, size_t size, int value)
{
	int i;

	if (!array)
	{
		/* Array is NULL */
		return (-1);
	}

	for (i = 0; i < (int)size; i++)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);

		if (array[i] == value)
		{
			return (i);
		}
	}

	return (-1);
}