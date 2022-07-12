#include "main.h"

/**
 * print_rev - prints strings in reverse
 * @s: string pointer
 */
void print_rev(char *s)
{
	int max_index = 0;

	/*move from first character to null*/
	for (; *s; s++)
	{
		max_index++;
	}

	/*print from last character to first*/
	for (s--; max_index > 0; s--)
	{
		_putchar(*s);
		max_index--;
	}
	_putchar('\n');
}
