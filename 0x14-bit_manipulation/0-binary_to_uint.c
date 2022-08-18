#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: the converted number, or 0 if:
 * 1. there is one or more chars in the string b that is not 0 or 1
 * 2. b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int n;

	n = str2bin(b);

	return (n);
}


/**
 * str2bin - converts a string of bits to a bit pattern
 * @b: the string to convert
 *
 * Return: the bit pattern
 */
unsigned int str2bin(const char *b)
{
	unsigned int i, mask, bin = 0, len = _strlen((char *)b);

	if (b == NULL)
	{
		return (0);
	}

	for (i = 0; b[i]; ++i)
	{
		if (b[i] == '0' || b[i] == '1')
		{
			if (b[i]  == '1')
			{
				mask = 1 << (len - 1);
				bin = bin | mask;
			}
		}
		else
		{
			return (0);
		}
		--len;
	}

	return (bin);
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
