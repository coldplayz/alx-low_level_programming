#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_nodeint_end -  adds a new node at the end of a listint_t list.
 * @head: a double pointer representing the address of the head of the list
 * @n: the integer to initialize the new node with
 *
 * Return: a pointer to the new node
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new, *temp = *head;
	/* temp is used so as not to change the address *head points to */

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;		/* new node is now pointing to NULL */

	if (listint_len(*head) == 0)
	{
		*head = new;		/*new node now head node, if it's the first node of the list*/
	}
	else
	{
		for (; temp; temp = (temp)->next)
		{
			if ((temp)->next == NULL)	/*when we reach the previous tail of the list...*/
			{
				(temp)->next = new;	/* ...let it point to the new tail */
				break;
			}
		}
	}

	return (new);
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
