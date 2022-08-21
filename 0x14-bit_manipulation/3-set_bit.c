#include "main.h"

/**
 * set_bit - set bit to 1 at given index
 * @n: number
 * @index: index within binary number
 * Return: 1 if success, or -1 if error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask = 1, len = sizeof(unsigned long int) * 8;

	if (index >= len)
	{
		return (-1);
	}

	mask <<= index;
	*n |= mask;

	return (1);
}
