#include "main.h"

/**
 * print_line - print the specified number of underscores
 * @n: integer specifying the number of underscores
 */
void print_line(int n)
{
	int counter = 1;

	if (!(n <= 0))
	{
		while (counter <= n)
		{
			_putchar('_');
			counter++;
		}
		_putchar('\n');
	}
	else
	{
		_putchar('\n');
	}
}
