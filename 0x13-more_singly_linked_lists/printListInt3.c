#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * printListInt3 - prints all elements of the loop-containing
 * structure listint_s with their addresses, traversing the list list only once
 * @h: the head of a loop-containing structure of type 'struct listint_s'
 * @loop_node: pointer to the node on which the loop occurs
 *
 * Return: the number of nodes in the list
 */
size_t printListInt3(const listint_t *h, const listint_t *loop_node)
{
	size_t m = 0, n = 0;
	listint_t *temp;

	temp = (listint_t *)h;
	/**
	 * m keeps track of the number of times
	 * the 'loop_node' address is accessed.
	 * When it's accessed/referenced for the
	 * second time, that signals that the
	 * loop is about to begin, and stops printing.
	 */
	for (; temp; temp = temp->next)
	{
		n++;
		if (temp == loop_node)
		{
			m++;
		}

		if (m == 2)
		{
			n--;
			break;
		}

		printf("[%p] %d\n", (void *)temp, temp->n);
	}
	printf("-> [%p] %d\n", (void *)loop_node, loop_node->n);

	return (n);
}
