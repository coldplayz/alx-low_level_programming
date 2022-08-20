#include <stdio.h>
#include <stdlib.h>
#include "main.h"


/**
 * get_bit - get bit at index
 * @n: number
 * @index: index within binary number
 * Return: bit 0 or 1, or -1 if error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask;
	unsigned int i, len = sizeof(unsigned long int) * 8;
	char c;

	if (index >= len)
	{
		return (-1);
	}

	mask = 1;
	for (i = 0; i < len; ++i)
	{
		c = n & mask ? '1' : '0';
		if (i == index)
		{
			return (c - '0');
		}
		n >>= 1;
	}

	return (c - '0');
}
