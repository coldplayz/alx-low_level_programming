#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list, even ones with a loop
 * @head: the address of the pointer to the head of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t n;
	listint_t *loop_node;

	if (head == NULL)
	{
		exit(98);
	}

	loop_node = list_loop_node(head);	/* get loop node */
	if (loop_node == NULL)
	{
		n = printListInt2(head);	/* print if no loop */
	}
	else
	{
		n = printListInt3(head, loop_node);
	}

	return (n);
}


/**
 * list_loop_node - returns the node on which a list's loop occurs, if any.
 * @head: the top of the list
 *
 * Return: a pointer to the loop node, or NULL if list has no loop
 */
listint_t *list_loop_node(const listint_t *head)
{
	int i, flag = 1, n = 0;
	listint_t *temp1, *temp2;

	temp1 = head->next;
	/**
	 * temp1 stores the address of successive structs, starting
	 * from the struct head points to. temp2 stores the address
	 * of every struct from the head to temp1 (for each run of
	 * the second FOR loop), each of which is compared to temp1
	 * for equality. By the end of this loop, if 'flag' is set
	 * to zero, then temp2 would hold the address of the loop
	 * node, or there's no loop in the list.
	 */
	for (;; temp1 = temp1->next)
	{
		n++;
		temp2 = (listint_t *)head;
		for (i = 0; i < n; i++)
		{
			if (temp2 == temp1 || temp1 == NULL)
			{
				flag = 0;
				break;
			}
			temp2 = temp2->next;
		}
		if (flag == 0)
		{
			break;
		}
	}
	if (temp1 == NULL)
	{
		return (NULL);
	}
	else if (flag == 0)
	{
		return (temp2);
	}
	return (temp2);
}


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

	for (; h; h = h->next)
	{
		n++;
		printf("[%p] %d\n", (void *)h, h->n);
	}

	return (n);
}


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
	printf("%lu\n", n);

	return (n);
}
