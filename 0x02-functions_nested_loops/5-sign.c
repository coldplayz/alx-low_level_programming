#include "main.h"

/**
 * print_sign - prints if a number is greater than 0 or not
 * @n: integer input
 *
 * Return: 1 if number is positve, 0 if zero, and -1 if negative
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	else
	{
		_putchar('-');
		return (-1);
	}
}
