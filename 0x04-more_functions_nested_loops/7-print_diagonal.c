#include "main.h"

/**
 * print_diagonal - prints a diagonal line in terminal
 * @n: integer determining number of line components
 */
void print_diagonal(int n)
{
	int spacer = n - 1, counter1 = 1, counter2 = 1;

	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		_putchar('\\');
		_putchar('\n');
		if (spacer)
		{
			while (counter1 <= spacer)
			{
				while (counter2 <= counter1)
				{
					_putchar(' ');
					counter2++;
				}
				_putchar('\\');
				_putchar('\n');
				counter1++;
				counter2 = 1;
			}
		}
	}
}
