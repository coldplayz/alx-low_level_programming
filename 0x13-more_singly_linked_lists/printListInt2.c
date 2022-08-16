#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * printListInt2 - prints all elements of the structure listint_s
 * with their addresses
 * @h: the head of a structure of type 'struct listint_s'
 *
 * Return: the number of nodes in the list
 */
size_t printListInt2(const listint_t *h)
{
	size_t n = 0;
	listint_t *temp;

	temp = (listint_t *)h;
	for (; temp; temp = temp->next)
	{
		n++;
		printf("[%p] %d\n", (void *)temp, temp->n);
	}

	return (n);
}
