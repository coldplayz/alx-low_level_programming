#include "main.h"

/**
 * more_numbers - prints numbers from 1 to 14, ten times
 */
void more_numbers(void)
{
	int c = 0, counter = 1;

	while (counter <= 10)
	{
		while (c <= 14)
		{
			if (c > 9)
			{
				_putchar((c / 10) + '0');
			}
			_putchar((c % 10) + '0');
			c++;
		}
		_putchar('\n');
		counter++;
		c = 0;
	}
}
