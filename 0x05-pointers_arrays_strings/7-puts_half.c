#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: pointer to char type
 *
 * Return: an integer length of the argument
 */
int _strlen(char *s)
{
	int len;

	for (len = 0; *s; s++)
	{
		len++;
	}

	return (len);
}

/**
 * puts_half - prints half of the string
 * @str: string pointer
 */
void puts_half(char *str)
{
	int len = _strlen(str), even_counter, odd_counter;

	if (len % 2 == 0)
	{
		str = str + (len / 2);
		for (even_counter = (len / 2); even_counter < len; even_counter++)
		{
			_putchar(*str);
			str++;
		}
	}
	else
	{
		str = str + ((len / 2) + 1);
		for (odd_counter = ((len / 2) + 1); odd_counter < len; odd_counter++)
		{
			_putchar(*str);
			str++;
		}
	}
	_putchar('\n');
}
