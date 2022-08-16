#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: pointer to the head node
 *
 * Return: the address of the node on which the list loops
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *loop_node;

	loop_node = list_loop_node(head);

	return (loop_node);
}
