#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * main - prints lowercase alphabets
 *
 * Return: Always 0
 */                                               int main(void)                                    {
	 int r;
	 int d = INT_MIN;

	 r = print_last_digit(INT_MIN);
	 _putchar(r + '0');
	 _putchar('\n');
	 printf("%d\n", d);
	 return (0);
}
