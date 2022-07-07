#include "main.h"

/**
 * print_square - prints squares using the # symbol
 * @size: integer argument
 */
void print_square(int size)
{
	int line = 1;
	int column = 1;

	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		while (line <= n)
		{
			while (column <= n)
			{
				_putchar('#');
				column++;
			}
			_putchar('\n');
			line++;
			column = 1;
		}
	}
}
