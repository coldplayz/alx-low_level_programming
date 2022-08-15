#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_nodeint -  adds a new node at the beginning of a listint_t list.
 * @head: a double pointer representing the address of the head of the list
 * @n: integer to initialize the new node with
 *
 * Return: a pointer to the new node
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = *head;		/*new node is now pointing to what head is pointing to*/

	*head = new;			/*new node is now the head node*/

	return (*head);
}
