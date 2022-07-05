#include "main.h"

/**
 * print_last_digit - prints last digit of a number
 * @n: integer input
 *
 * Return: last digit
 */
int print_last_digit(int n)
{
	int mod;

	if (n < 0)
	{
		n *= -1;
	}
	mod = n % 10;
	_putchar(mod + '0');
	return (mod);
}
