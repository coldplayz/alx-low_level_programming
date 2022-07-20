#include "main.h"

/**
 * _print_rev_recursion -  prints a string in reverse
 * @s: pointer to string to print in reverse
 */
void _print_rev_recursion(char *s)
{
	if (*s == 0)
	{
		_putchar(*s);
		return;
	}

	_print_rev_recursion((s + 1));
	_putchar(*s);
}
