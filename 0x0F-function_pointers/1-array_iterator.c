#include <stdlib.h>
#include "function_pointers.h"

/**
 * array_iterator - executes a callback on an array
 * @array: pointer to the first element of the array to execute the callback on
 * @size: array size
 * @action: callback function
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if ((action == NULL) || (array == NULL) || (size <= 0))
	{
		exit(EXIT_SUCCESS);
	}

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
