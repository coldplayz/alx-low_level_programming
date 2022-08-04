#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

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
			if ((count == (valid - 1)) && (valid > 1))
				printf(", %c", va_arg(ap, char));
			else if ((valid - 1) == 0)
				printf("%c", va_arg(ap, char));
			else
				printf("%c, ", va_arg(ap, char));
			break;
		case 'i':
			if ((count == (valid - 1)) && (valid > 1))
				printf(", %d", va_arg(ap, int));
			else if ((valid - 1) == 0)
				printf("%d", va_arg(ap, int));
			else
				printf("%d, ", va_arg(ap, int));
			break;
		case 'f':
			if ((count == (valid - 1)) && (valid > 1))
				printf(", %f", va_arg(ap, float));
			else if ((valid - 1) == 0)
				printf("%f", va_arg(ap, float));
			else
				printf("%d, ", va_arg(ap, float));
			break;
		case 's':
			ptc = va_arg(ap, char *);
			switch (ptc == NULL)
			{
				case 1:
					if ((count == (valid - 1)) && (valid > 1))
						printf(", (nil)");
					else if ((valid - 1) == 0)
						printf("(nil)");
					else
						printf("(nil), ");
					break;
				case 0:
					if ((count == (valid - 1)) && (valid > 1))
						printf(", %s", ptc);
					else if ((valid - 1) == 0)
						printf("%s", ptc);
					else
						printf("%s, ", ptc);
			}
	}
}
