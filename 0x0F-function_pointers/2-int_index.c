#include <stdlib.h>
#include "function_pointers.h"

/**
 * int_index - searches for an integer
 * @array: the array to search in
 * @size: the array size
 * @cmp: a pointer to the callback to compare with
 *
 * Return: the index of the first element for which the
 * cmp function does not return 0, or -1 if size <= 0 and/or no matches
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if ((cmp == NULL) || (array == NULL))
	{
		return (-1);
	}

	if (size <= 0)
	{
		return (-1);
	}

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
		{
			return (i);
		}
	}

	return (-1);
}
