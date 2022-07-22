#include "main.h"

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

/**
 * _strcat - concatenates two strings
 * @dest: pointer to string to be modified
 * @src: pointer to modifier string
 *
 * Return: a pointer to the modified string
 */
char *_strcat(char *dest, char *src)
{
	int i, dest_size;

	dest_size = _strlen(dest);
	for (i = 0; *(src + i); i++)
	{
		/*add all characters in src to dest*/
		/*starting from NULL character position*/
		*(dest + dest_size) = *(src + i);
		dest_size++;
	}
	*(dest + dest_size) = '\0';

	return (dest);
}
