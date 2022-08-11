#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_list - prints all elements of the structure list_t
 * @h: the head of a structure of type 'struct list_s'
 *
 * Return: the number of nodes in the list
 */
size_t print_list(const list_t *h)
{
	size_t n = 0;

	for (; h; h = h->next)
	{
		n++;
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%u] %s\n", h->len, h->str);
		}
	}

	return (n);
}
