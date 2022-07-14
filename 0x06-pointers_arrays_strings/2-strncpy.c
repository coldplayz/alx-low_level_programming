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
 * _strncpy - copies src string to dest
 * @dest: pointer to string to be overwritten
 * @src: pointer to modifier string
 * @n: integer determining number of bytes (characters) to be copied
 *
 * Return: a pointer to the modified string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	if (n > _strlen(src))
	{
		n = _strlen(src);
	}

	for (i = 0; n > 0; i++)
	{
		/*copy 'n' characters in src to dest*/
		/*starting from first character*/
		*(dest + i) = *(src + i);
		n--;
	}

	*(dest + i) = '\0';

	return (dest);
}
