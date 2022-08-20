#include <stdio.h>
#include <stdlib.h>
#include "main.h"


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
