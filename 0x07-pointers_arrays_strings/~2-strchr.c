#include "main.h"

/**
 * _strchr - searches string s for character c
 * @s: string to search in
 * @c: character to search for
 *
 * Return: returns a pointer to the first occurrence of the character c in
 * the string s, or NULL if the character is not found
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; *(s + i); i++)
	{
		if (*(s + i) == c)
		{
			return (s + i);
		}
	}

	return ('\0');
}
