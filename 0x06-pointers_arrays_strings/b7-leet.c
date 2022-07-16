#include "main.h"

char *leet(char *s)
{
	int i;

	for (i = 0; *(s + i); i++)
	{
		leet_map((s + i));
	}
	return (s);
}


/**
 * leet_map - encodes leet characters
 * @c: char to possibly encode
 */
void leet_map(char *c)
{
	char leet_char[] = {'a', 'A', 'e', 'E', 'o', 'O', 't', 'T', 'l', 'L'};
	int leet_map[] = {4, 4, 3, 3, 0, 0, 7, 7, 1, 1};
	int i;

	for (i = 0; i < 10; i++)
	{
		if (*c == leet_char[i])
		{
			*c = leet_map[i] + 48;
		}
	}
}
