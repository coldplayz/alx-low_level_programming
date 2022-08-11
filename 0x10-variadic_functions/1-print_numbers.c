#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_numbers - prints integers followed by a new line
 * @separator:  the string to be printed between numbers
 * @n: the number of integers passed to the function
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list ap;

	va_start(ap, n);
	for (i = 0; i < n; i++)
	{
		if (i == (n - 1))
		{
			printf("%d\n", va_arg(ap, int));
		}
		else
		{
			if (separator != NULL)
			{
				printf("%d%s", va_arg(ap, int), separator);
			}
			else
			{
				printf("%d", va_arg(ap, int));
			}
		}
	}

	if (n == 0)
	{
		printf("\n");
	}
	va_end(ap);
}
