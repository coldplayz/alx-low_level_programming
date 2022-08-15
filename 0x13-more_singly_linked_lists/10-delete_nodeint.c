#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - deletes
 * the node at index index of a listint_t linked list.
 * @head: holds the address of the pointer to the first node
 * @index: the index at which to delete the node/structure
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t  *temp, *temp2;
	unsigned int i, list_len;

	list_len = listint_len(*head);
	if (index >= list_len || list_len == 0)
	{
		return (-1);
	}

	temp = *head;
	if (index > 0)
	{
		for (i = 0; i < index; i++)
		{
			/**
			 * By the end of this loop, temp2 will hold the address
			 * of the node before the index position, and temp will
			 * hold the address of the struct currently at the index position
			 */
			temp2 = temp;
			temp = temp->next;
		}
		temp2->next = temp->next;	/* struct at temp2 now points two structs ahead */
		free(temp);			/* frees the memory allocated to the deleted struct */
	}
	else if (index == 0)			/* if first node is to be deleted */
	{
		pop_listint2(head);
	}
	return (1);
}


/**
 * pop_listint2 - deletes the head node of a listint_t linked list.
 * @head: a pointer storing the address of the pointer to the list head
 */
void pop_listint2(listint_t **head)
{
	listint_t *head_cpy;

	if (listint_len(*head) == 0)
	{
		;
	}
	else
	{
		head_cpy = *head;
		*head = (*head)->next;
		free(head_cpy);
	}
}
