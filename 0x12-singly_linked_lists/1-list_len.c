#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * list_len - determines the number of elements of the structure list_t
 * @h: the head of a structure of type 'struct list_s'
 *
 * Return: the number of nodes in the list
 */
size_t list_len(const list_t *h)
{
	size_t n = 0;

	for (; h; h = h->next)
	{
		n++;
	}

	return (n);
}
