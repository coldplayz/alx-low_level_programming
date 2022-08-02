#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - creates a new dog
 * @name: pointer to dog name string
 * @age: dog age
 * @owner: pointer to dog owner name string
 *
 * Return: pointer to the newly created dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *ptr;

	ptr = malloc(sizeof(dog_t));
	if (ptr == NULL)
	{
		return (NULL);
	}

	ptr->name = strdup2(name);
	if (ptr->name == NULL)
	{
		free(ptr);
		return (NULL);
	}

	ptr->age = age;

	ptr->owner = strdup2(owner);
	if (ptr->owner == NULL)
	{
		free(ptr->name);
		free(ptr);
		return (NULL);
	}

	return (ptr);
}


/**
 * strdup2 - copies a string to newly allocated memory.
 * @str: pointer string to make a duplicate of.
 *
 * Return: a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 */
char *strdup2(char *str)
{
	int i, j;
	char *ptc;

	if (str == NULL)
	{
		return (NULL);
	}

	j = _strlen(str);
	ptc = malloc((j + 1) * sizeof(char));
	if (ptc == NULL)
	{
		return (NULL);
	}

	/*copy all the xters of str, including '\0'*/
	for (i = 0; i <= j; i++)
	{
		*(ptc + i) = *(str + i);
	}

	return (ptc);
}



/**
 * _strlen - returns the length of a string
 * @s: pointer to char type
 *
 * Return: an integer length of the argument
 */
int _strlen(char *s)
{
	int len, shift = 0;

	for (len = 0; *(s + shift);)
	{
		len++;
		shift++;
	}

	return (len);
}
