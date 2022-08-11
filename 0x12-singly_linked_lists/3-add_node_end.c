#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end -  adds a new node at the end of a list_t list.
 * @head: a double pointer representing the address of the head of the list
 * @str: pointer to the string to duplicate in the new node
 *
 * Return: a pointer to the new node
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *temp = *head;
	/* temp is used so as not to change the address *head points to */

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	if (str == NULL)
	{
		new->str = strdup("nil");
		new->len = 0;
	}
	else
	{
		new->str = strdup(str);	/*store a copy of the string*/
		new->len = _strlen(str);
	}
	new->next = NULL;		/*new node is now pointing to what head is pointing to*/

	if (list_len(*head) == 0)
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
 * _strlen - returns the length of a string
 * @s: pointer to char type
 *
 * Return: an integer length of the argument
 */
int _strlen(const char *s)
{
	int len, shift = 0;

	for (len = 0; *(s + shift);)
	{
		len++;
		shift++;
	}

	return (len);
}


/**
 * list_len - determines the number of elements of the structure list_t
 * @h: the head of a structure of type 'struct list_s'
 *
 * Return: the number of nodes in the list
 */
size_t list_len(const list_t *h)
{
	size_t n = 0;

	for (; h; h = h->next)
	{
		n++;
	}

	return (n);
}
