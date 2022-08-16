#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list.
 * @h: pointer to the head node
 *
 * Return: the size of the freed list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t n;
	listint_t *loop_node;

	if ((*h) == NULL)
	{
		return (0);
	}

	loop_node = list_loop_node(*h);	/* get loop node */
	if (loop_node == NULL)
	{
		n = freeListInt2(h);	/* print if no loop */
	}
	else
	{
		n = freeListInt3(h, loop_node);
	}

	return (n);
}


/**
 * freeListInt2 - frees all elements of
 * the structure listint_s, setting the head to NULL
 * @h: the head of a structure of type 'struct listint_s'
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


/**
 * freeListInt3 - frees all elements of
 * the loop-contining structure listint_s, setting the head to NULL
 * @h: the head of a structure of type 'struct listint_s'
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
