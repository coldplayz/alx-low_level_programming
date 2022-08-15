#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - frees a listint_t linked list, and sets the head to NULL
 * @head: pointer to the first node of the list
 */
void free_listint2(listint_t **head)
{
	listint_t *temp2, *temp = *head;

	for (; temp; temp = temp2)
	{
		temp2 = temp->next;
		free(temp);
	}

	*head = NULL;
}
