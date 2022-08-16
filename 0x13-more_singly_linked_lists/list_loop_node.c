#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * list_loop_node - returns the node on which a list's loop occurs, if any.
 * @head: the top of the list
 *
 * Return: a pointer to the loop node, or NULL if list has no loop
 */
listint_t *list_loop_node(const listint_t *head)
{
	int i, flag = 1, n = 0;
	listint_t *temp1, *temp2;

	temp1 = head->next;
	for (;; temp1 = temp1->next)
	{
		n++;
		temp2 = (listint_t *)head;
		for (i = 0; i < n; i++)
		{
			if (temp2 == temp1 || temp1 == NULL)
			{
				flag = 0;
				break;
			}
			temp2 = temp2->next;
		}
		if (flag == 0)
		{
			break;
		}
	}

	if (temp1 == NULL)
	{
		return (NULL);
	}
	else if (flag == 0)
	{
		return (temp2);
	}
	return (temp2);
}
