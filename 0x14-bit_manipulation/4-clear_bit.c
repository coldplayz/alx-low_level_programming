#include "main.h"

/**
 * clear_bit - clear bit to 0 at given index
 * @n: number
 * @index: index within binary number
 * Return: 1 if success, or -1 if error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int i, mask, n_copy = *n, j = 1, len = sizeof(mask) * 8;
	char c;

	if (index >= len)
	{
		return (-1);
	}

	mask = 1;
	for (i = 0; i < len; ++i)
	{
		c = n_copy & mask ? '1' : '0';
		if (i == index)
		{
			/* get the bit at the specified index */
			if ((c - '0') == 0)
			{
				return (1);
			}
			else
			{
				/* if 1, left-shift mask by index bits and XOR with n... */
				/* ...to flip bit 1 at specified index of the bit pattern. */
				mask = j << index;
				*n ^= mask;
			}
		}
		n_copy >>= 1;
	}

	return (1);
}
