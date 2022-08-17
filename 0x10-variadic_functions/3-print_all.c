#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - prints data objects of any of the specified types
 * @format: pointer to the user-defined format string
 */
void print_all(const char * const format, ...)
{
	int i, count = 0;
	va_list ap;
	std structure;

	while (!format)
	{
		printf("(nil)\n");
		exit(EXIT_SUCCESS);
	}
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		switch (format[i])
		{
			case 'c':
				structure.c = va_arg(ap, int);
				print_any(structure, format[i], count);
				count++;
				break;
			case 'i':
				structure.i = va_arg(ap, int);
				print_any(structure, format[i], count);
				count++;
				break;
			case 'f':
				structure.f = va_arg(ap, double);
				print_any(structure, format[i], count);
				count++;
				break;
			case 's':
				structure.s = va_arg(ap, char *);
				print_any(structure, format[i], count);
				count++;
				break;
		}
		i++;
	}
	va_end(ap);
	printf("\n");
}

/**
 * print_any - prints data of any of a specified number of data types
 * @structure: a structure that stores data types of the standard format.
 * @c: the character that determines which,
 * out of several, block of code to execute
 * @count: the number of times arguments have been printed
 */
void print_any(std structure, char c, int count)
{
	switch (c)
	{
		case 'c':
			switch (count)
			{
				case 0:
					printf("%c", structure.c);
					break;
				default:
					printf(", %c", structure.c);
			}
			break;
		case 'i':
			switch (count)
			{
				case 0:
					printf("%d", structure.i);
					break;
				default:
					printf(", %d", structure.i);
			}
			break;
		case 'f':
			switch (count)
			{
				case 0:
					printf("%f", structure.f);
					break;
				default:
					printf(", %f", structure.f);
			}
			break;
		default:
			print_any_ext(structure, c, count);
	}
}


/**
 * print_any_ext - an extension of print_any().
 * @structure: structure containing standard format data types.
 * @c: format character.
 * @count: number of arguments printed.
 */
void print_any_ext(std structure, char c, int count)
{
	switch (c)
	{
		case 's':
			switch (count)
			{
				case 0:
					if (structure.s == NULL)
					{
						printf("(nil)");
						break;
					}
					printf("%s", structure.s);
					break;
				default:
					if (structure.s == NULL)
					{
						printf(", (nil)");
						break;
					}
					printf(", %s", structure.s);
			}
	}
}
