#include "main.h"

/**
 * print_triangle - prints a triangle of # symbols
 * @size: integer to determine triangle size
 */
void print_triangle(int size)
{
	int space = size - 1, symbol = 1, sp_counter = 1, sy_counter = 1;

	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		while (size >= 1)
		{
			while (sp_counter <= space)
			{
				_putchar(' ');
				sp_counter++;
			}
			space--;
			sp_counter = 1;

			while (sy_counter <= symbol)
			{
				_putchar('#');
				sy_counter++;
			}
			_putchar('\n');
			symbol++;
			sy_counter = 1;
			size--;
		}
	}
}
