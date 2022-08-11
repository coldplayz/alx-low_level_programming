#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	size_t a;
    list_t *head;

    head = NULL;

    a = list_len(head);
    printf("%lu\n", a);

    return (0);
}



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
