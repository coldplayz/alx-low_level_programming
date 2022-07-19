#include "main.h"

/**
 * _strchr - searches string s for character c, including the NULL character
 * @s: string to search in
 * @c: character to search for
 *
 * Return: returns a pointer to the first occurrence of the character c in
 * the string s, or NULL if the character is not found
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; i < (_strlen(s) + 1); i++)
	{
		if (*(s + i) == c)
		{
			return (s + i);
		}
	}

	return ('\0');
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
