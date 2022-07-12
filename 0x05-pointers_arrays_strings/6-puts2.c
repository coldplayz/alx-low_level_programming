#include "main.h"

/**
 * puts2 - print every other string character
 * @str: string pointer
 */
void puts2(char *str)
{
	int counter = 2;

	for (; *str; str++)
	{
		if (counter % 2 == 0)
		{
			_putchar(*str);
		}
		counter++;
	}
	_putchar('\n');
}
