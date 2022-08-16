#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head: the first node
 * @index: the index of the node, starting at 0
 *
 * Return: the nth node of a listint_t linked list.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int list_len, n;
	listint_t *nth_node, *temp;

	temp = head;
	list_len = listint_len(head);
	if (index >= list_len)
	{
		return (NULL);
	}

	for (n = 0; n <= index; n++)
	{
		nth_node = temp;
		temp = temp->next;
	}

	return (nth_node);
}


/**
 * listint_len - determines the number of elements of the structure listint_s
 * @h: the head of a structure of type 'struct listint_s'
 *
 * Return: the number of nodes in the list
 */
size_t listint_len(const listint_t *h)
{
	size_t n = 0;
	listint_t *temp;

	temp = (listint_t *)h;
	for (; temp; temp = temp->next)
	{
		n++;
	}

	return (n);
}
