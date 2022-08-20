#include "main.h"

/**
 * flip_bits - determine how many bits to flip to get from one num to another
 * @n: number
 * @m: number2
 * Return: how many bits differ
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int mask;
	unsigned int i, diff = 0, len = sizeof(unsigned long int) * 8;
	char c, d;

	mask = 1;
	for (i = 0; i < len; ++i)
	{
		c = n & mask ? '1' : '0';
		d = m & mask ? '1' : '0';
		if (c != d)
		{
			diff++;
		}
		n >>= 1;
		m >>= 1;
	}

	return (diff);
}
