#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * freeListInt3 - frees all elements of
 * the loop-contining structure listint_s, setting the head to NULL
 * @h: the address of a pointer to the
 * head of a structure of type 'struct listint_s'
 * @loop_node: the node on which the list loops
 *
 * Return: the size of the free'd list
 */
size_t freeListInt3(listint_t **h, listint_t *loop_node)
{
	size_t m = 0, n = 0;
	listint_t *temp, *temp2;

	temp = *h;
	temp2 = temp;
	for (; temp; temp = temp2)
	{
		if (temp == loop_node)
		{
			m++;
		}

		if (m == 2)
		{
			break;
		}

		temp2 = temp2->next;
		free(temp);
		n++;
	}
	*h = NULL;

	return (n * sizeof(listint_t));
}
