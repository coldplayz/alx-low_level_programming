#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint - frees a listint_t linked list
 * @head: pointer to the first node of the list
 */
void free_listint(listint_t *head)
{
	listint_t *temp2, *temp = head;

	for (; temp; temp = temp2)
	{
		temp2 = temp->next;
		free(temp);
	}
}
