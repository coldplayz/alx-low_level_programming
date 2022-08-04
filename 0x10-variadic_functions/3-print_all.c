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
	int i, j, valid, count = 0;
	char *std_form = "cifs";
	va_list ap;

	va_start(ap, format);
	valid = nvc(std_form, format);

	i = 0;
	while (format[i])
	{
		j = mi(std_form, format[i]);
		while (j != -1)
		{
			print_any(ap, std_form[j], valid, count);
			count++;
			break;
		}
		i++;
	}
	printf("\n");
}


/**
 * nvc - determines number of characters in user_form
 * that matches any of the characters in std_form
 * @std_form: a pointer to the standard format string
 * @user_form: a pointer to the user-defined format string
 *
 * Return: an int representing the number of matches
 */
int nvc(const char *const std_form, const char *const user_form)
{
	int i, j, count = 0;

	for (i = 0; user_form[i]; i++)
	{
		for (j = 0; std_form[j]; j++)
		{
			if (user_form[i] == std_form[j])
			{
				count++;
				break;
			}
		}
	}

	return (count);
}


/**
 * mi - finds the index, in std_form, that xter first finds a match
 * @std_form: a pointer to the string pattern
 * @xter: the character to match
 *
 * Return: a non-negative integer representing
 * the matching index in std_form; or -1 if no match is found
 */
int mi(const char *const std_form, char xter)
{
	int i;

	for (i = 0; std_form[i]; i++)
	{
		if (std_form[i] == xter)
		{
			return (i);
		}
	}

	return (-1);
}


/**
 * print_any - prints data of any of a specified number of data types
 * @ap: an initialized argument pointer of type va_list
 * @c: the character that determines which,
 * out of several, blocks of code to execute
 * @valid: the number of matching
 * characters between std and user-defined formats
 * @count: the number of times arguments have been printed
 */
void print_any(va_list ap, char c, int valid, int count)
{
	char *ptc;

	switch (c)
	{
		case 'c':
			if (((valid - 1) == 0) || ((count == (valid - 1)) && (valid > 1)))
				printf("%c", va_arg(ap, int));
			else
				printf("%c, ", va_arg(ap, int));
			break;
		case 'i':
			if (((valid - 1) == 0) || ((count == (valid - 1)) && (valid > 1)))
				printf("%d", va_arg(ap, int));
			else
				printf("%d, ", va_arg(ap, int));
			break;
		case 'f':
			if (((valid - 1) == 0) || ((count == (valid - 1)) && (valid > 1)))
				printf("%f", va_arg(ap, double));
			else
				printf("%f, ", va_arg(ap, double));
			break;
		case 's':
			ptc = va_arg(ap, char *);
			switch (ptc == NULL)
			{
				case 1:
					if (((valid - 1) == 0) || ((count == (valid - 1)) && (valid > 1)))
						printf("(nil)");
					else
						printf("(nil), ");
					break;
				case 0:
					if (((valid - 1) == 0) || ((count == (valid - 1)) && (valid > 1)))
						printf("%s", ptc);
					else
						printf("%s, ", ptc);
			}
	}
}
