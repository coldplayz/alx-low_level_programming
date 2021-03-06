#include "main.h"

/**
 * print_last_digit - prints last digit of a number
 * @n: integer input
 *
 * Return: last digit
 */
int print_last_digit(int n)
{
	if (n < 0)
	{
		_putchar(((n % 10) * (-1)) + '0');
		return (((n % 10) * (-1)));
	}
	else
	{
		_putchar((n % 10) + '0');
		return (n % 10);
	}
}
