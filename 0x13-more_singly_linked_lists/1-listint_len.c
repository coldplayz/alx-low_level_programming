#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * listint_len - determines the number of elements of the structure listint_s
 * @h: the head of a structure of type 'struct listint_s'
 *
 * Return: the number of nodes in the list
 */
size_t listint_len(const listint_t *h)
{
	size_t n = 0;

	for (; h; h = h->next)
	{
		n++;
	}

	return (n);
}
