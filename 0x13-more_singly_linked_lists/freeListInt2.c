#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * freeListInt2 - frees all elements of
 * the structure listint_s, setting the head to NULL
 * @h: the address of the pointer to the head
 * of a structure of type 'struct listint_s'
 *
 * Return: the size of the free'd list
 */
size_t freeListInt2(listint_t **h)
{
	size_t n = 1;
	listint_t *temp, *temp2;

	temp = (*h)->next;
	temp2 = temp;
	free(*h);
	*h = NULL;
	for (; temp; temp = temp2)
	{
		n++;
		temp2 = temp2->next;
		free(temp);
	}

	return (n * sizeof(listint_t));
}
