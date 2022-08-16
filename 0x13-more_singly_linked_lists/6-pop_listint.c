#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t
 * linked list, and returns the head node’s data (n).
 * @head: a pointer storing the address of the pointer to the list head
 *
 * Return: the data of the head node deleted
 */
int pop_listint(listint_t **head)
{
	listint_t *head_cpy;
	int head_data;

	if (listint_len(*head) == 0)
	{
		return (0);
	}

	head_cpy = *head;
	head_data = (*head)->n;
	*head = (*head)->next;
	free(head_cpy);

	return (head_data);
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
