#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a list_t linked list
 * @head: pointer to the first node of the list
 */
void free_list(list_t *head)
{
	list_t *temp2, *temp = head;

	for (; temp; temp = temp2)
	{
		temp2 = temp->next;
		free(temp->str);
		free(temp);
	}
}
