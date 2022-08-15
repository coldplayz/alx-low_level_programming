#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint - prints all elements of the structure listint_s
 * @h: the head of a structure of type 'struct listint_s'
 *
 * Return: the number of nodes in the list
 */
size_t print_listint(const listint_t *h)
{
	size_t n = 0;

	for (; h; h = h->next)
	{
		n++;
		printf("%d\n", h->n);
	}

	return (n);
}
