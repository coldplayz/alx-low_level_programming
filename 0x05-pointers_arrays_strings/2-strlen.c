#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: pointer to char type
 *
 * Return: an integer length of the argument
 */
int _strlen(char *s)
{
	int len;

	for (len = 0; *s; s++)
	{
		len++;
	}

	return (len);
}
