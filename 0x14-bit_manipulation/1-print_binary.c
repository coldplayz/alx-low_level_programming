#include "main.h"
#include <stdio.h>
/**
 * print_binary - converts unsigned int to binary and prints
 * @n: unsigned int
 * Return: binary
 */
void print_binary(unsigned long int n)
{
	unsigned long int i, mask, flag = 0, len = sizeof(unsigned long int) * 8;
	char c;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	mask = (unsigned long int)(1 << (len - 1));
	for (i = 0; i < len; ++i)
	{
		c = n & mask ? '1' : '0';
		if (c == '1')
		{
			flag = 1;
		}

		if (flag)
		{
			_putchar(c);
		}
		n <<= 1;
	}
}
