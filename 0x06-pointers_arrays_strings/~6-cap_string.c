#include "main.h"

/**
 * cap_string - converts alpha characters after word separators to uppercase
 * @s: string to manipulate
 *
 * Return: pointer to modified string
 */
char *cap_string(char *s)
{
	int i;

	for (i = 0; *(s + i); i++)
	{
		/*check if a lowercase letter*/
		if ((*(s + i) >= 97) && (*(s + i) <= 122))
		{
			/*check if previous character is a valid separator*/
			if (w_separator(*(s + (i - 1))))
			{
				*(s + i) = *(s + i) - 32;
			}
		}
	}
	return (s);
}


/**
 * w_separator - checks if a character is a word separator
 * @c: character to check
 *
 * Return: 1 if c is word separator; 0 otherwise
 */
int w_separator(char c)
{
	int i;

	char arr[] = {32, 9, 10, 44, 59, 46, 33, 63, 34, 40, 41, 123, 125};

	for (i = 0; i < 13; i++)
	{
		if (c == arr[i])
		{
			return (1);
		}
	}
	return (0);
}
