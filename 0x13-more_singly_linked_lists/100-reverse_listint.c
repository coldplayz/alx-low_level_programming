#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list.
 * @head: pointer to pointer to listint_t
 *
 * Return: a pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *temp1, *temp2;

	if (*head == NULL)
	{
		return (NULL);
	}

	temp1 = NULL;
	for (; temp2; )
	{
		temp2 = (*head)->next;
		(*head)->next = temp1;
		temp1 = *head;
		*head = temp2;
	}
	*head = temp1;

	return (*head);
}
