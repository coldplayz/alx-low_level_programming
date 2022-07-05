#include "main.h"

/**
 * main - prints lowercase alphabets
 *
 * Return: Always 0
 */
int main(void)
{
	print_alphabet();
	return (0);
}

/**
 * print_alphabet - defines the function that prints lowercases
 */
void print_alphabet(void)
{
	char c = 'a';

	while (c <= 'z')
	{
		_putchar(c);
		c++;
	}
	_putchar('\n');
}
