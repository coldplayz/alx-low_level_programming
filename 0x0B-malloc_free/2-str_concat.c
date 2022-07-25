#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates to strings, s1 and s2.
 * @s1: pointer to first string
 * @s2: pointer to second string
 *
 * Return: a newly allocated space in memory which contains
 * the contents of s1, followed by the contents of s2, and null terminated.
 */
char *str_concat(char *s1, char *s2)
{
	int i, j, k, m = 0;
	char *ptc;

	if (s1 != NULL)
	{
		j = _strlen(s1);
	}
	if (s2 != NULL)
	{
		k = _strlen(s2);
	}
	/*allocate enough space to contain the two*/
	/*strings plus a null character terminator*/
	ptc = malloc((j + k + 1) * sizeof(char));
	if (ptc == NULL)
	{
		return (NULL);
	}

	if (s1 != NULL)
	{
		for (i = 0; i < j; i++)
		{
			*(ptc + m) = *(s1 + i);
			m++;
		}
	}
	if (s2 != NULL)
	{
		for (i = 0; i < k; i++)
		{
			*(ptc + m) = *(s2 + i);
			m++;
		}
	}
	*(ptc + m) = 0;

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
