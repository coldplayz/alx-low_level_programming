#include "main.h"
#include <stdio.h>
#include <limits.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	print_number(-3);
	_putchar('\n');
	print_number(0);
	_putchar('\n');
	print_number(-33);
	_putchar('\n');
	print_number(33);
	_putchar('\n');
	print_number(-333333);
	_putchar('\n');
	print_number(333333);
	_putchar('\n');
	print_number(INT_MAX);
	_putchar('\n');
	print_number(INT_MIN);
	_putchar('\n');

	return (0);
}
