
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
 * _strncat - concatenates two strings, adding only 'n' bytes to dest
 * @dest: pointer to string to be modified
 * @src: pointer to modifier string
 * @n: integer determining number of bytes (characters) to be appended
 *
 * Return: a pointer to the modified string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, dest_size;

	dest_size = _strlen(dest);
	for (i = 0; n > 0; i++)
	{
		/*add 'n' characters in src to dest*/
		/*starting from NULL character position*/
		*(dest + dest_size) = *(src + i);
		dest_size++;
		n--;
	}
	
	if (n < _strlen(src))
	{
		*(dest + dest_size) = '\0';
	}

	return (dest);
}
