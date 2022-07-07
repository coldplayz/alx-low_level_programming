#include "main.h"

/**
 * print_numbers - prints numbers 0 - 9
 */
void print_numbers(void)
{
	int c = '0';

	while (c <= '9')
	{
		_putchar(c);
		c++;
	}
	_putchar('\n');
}
