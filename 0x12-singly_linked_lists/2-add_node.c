#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node -  adds a new node at the beginning of a list_t list.
 * @head: a double pointer representing the address of the head of the list
 * @str: pointer to the string to duplicate in the new node
 *
 * Return: a pointer to the new node
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;

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
	new->next = *head;		/*new node is now pointing to what head is pointing to*/

	*head = new;			/*new node is now the head node*/

	return (*head);
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
