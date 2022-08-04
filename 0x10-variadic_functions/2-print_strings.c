#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_strings - prints strings followed by a new line
 * @separator: the string to be printed between the strings
 * @n: the number of strings passed to the function
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list ap;
	char *val;

	va_start(ap, n);
	for (i = 0; i < n; i++)
	{
		val = va_arg(ap, char *);
		if ((i == (n - 1)) && (val != NULL))
		{
			printf("%s\n", val);
		}
		else if (i == (n - 1))
		{
			printf("(nil)\n");
		}
		else
		{
			if ((val != NULL) && (separator != NULL))
			{
				printf("%s%s", val, separator);
			}
			else if ((val != NULL) && (separator == NULL))
			{
				printf("%s", val);
			}
			else if ((val == NULL) && (separator != NULL))
			{
				printf("(nil)%s", separator);
			}
			else
			{
				printf("(nil)");
			}
		}
	}
	va_end(ap);
}
