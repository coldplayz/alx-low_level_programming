#include "main.h"
#include <stdlib.h>

/**
 * _strdup - copies a string to newly allocated memory.
 * @str: pointer string to make a duplicate of.
 *
 * Return: a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 */
char *_strdup(char *str)
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
