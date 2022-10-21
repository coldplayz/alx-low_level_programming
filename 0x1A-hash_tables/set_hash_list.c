#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"


#ifndef SET_HASH_LIST_C
#define SET_HASH_LIST_C

/**
 * set_hash_list - inserts a new node or updates an existing one.
 * @list: address of linked list of interest.
 * @key: a string.
 * @value: a string representing data to store.
 *
 * Return: 1 on successful insertion or update; 0 otherwise.
 */
int set_hash_list(
		hash_node_t **list, const char *key, const char *value)
{
	hash_node_t *tmp, *new_node;
	char *val;

	tmp = *list;
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			/* update existing value */
			val = strdup(value);
			if (!val)
			{
				return (0);
			}
			free(tmp->value); /* free previous address */
			tmp->value = val; /* assign new address */
			return (1);
		}

		tmp = tmp->next;
	}

	/* no existing node for key, insert new node at list start */
	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
		return (0);
	new_node->key = key;
	val = strdup(value);
	if (!val)
	{
		return (0);
	}
	new_node->value = val;
	new_node->next = *list;
	*list = new_node;

	return (1);
}
#endif /* SET_HASH_LIST_C */
