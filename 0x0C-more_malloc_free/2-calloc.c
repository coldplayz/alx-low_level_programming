#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array, using malloc.
 * @nmemb: an unsigned int representing the number of array members
 * @size: the length of the array
 *
 * Return: a pointer to the allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	void *ptv;
	/*int *pti;*/

	if ((nmemb == 0) || (size == 0))
	{
		return (NULL);
	}
	ptv = malloc(nmemb * size);
	if (ptv == NULL)
	{
		return (NULL);
	}
	/*pti = (int *)ptv;*/

	for (i = 0; i < (nmemb * size); i++)
	{
		*((char *)ptv + i) = 0;
	}
	/*ptv = (void *)pti;*/

	return (ptv);
}
