#include "main.h"

/**
 * string_toupper - changes from lower to upper case
 * @s: string to manipulate
 *
 * Return: a pointer to the modified string
 */
char *string_toupper(char *s)
{
	int i;

	for (i = 0; *(s + i); i++)
	{
		/*check if character is alpha*/
		if ((*(s + i) >= 97) && (*(s + i) <= 122))
		{
			*(s + i) = *(s + i) - 32;
		}
	}

	return (s);
}
