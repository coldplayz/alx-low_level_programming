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
	/**
	 * temp1 stores the address of successive structs, starting
	 * from the struct head points to. temp2 stores the address
	 * of every struct from the head to temp1 (for each run of
	 * the second FOR loop), each of which is compared to temp1
	 * for equality. By the end of this loop, if 'flag' is set
	 * to zero, then temp2 would hold the address of the loop
	 * node, or there's no loop in the list.
	 */
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
