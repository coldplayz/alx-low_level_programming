#include <stdio.h>

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
