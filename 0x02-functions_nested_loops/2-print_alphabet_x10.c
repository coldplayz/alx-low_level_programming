#include "main.h"

/**
 * print_alphabet_x10 - defines the function that prints lowercases x10
 */
void print_alphabet_x10(void)
{
	char c = 'a';
	int d = 0;

	while (d < 10)
	{
		while (c <= 'z')
		{
			_putchar(c);
			c++;
		}
		_putchar('\n');
		d++;
		c = 'a';
	}
}
