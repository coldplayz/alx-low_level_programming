#include "main.h"

char *rot13(char *s)
{
	int i;

	for (i = 0; *(s + i); i++)
	{
		rot13_map((s + i));
	}
	return (s);
}


/**
 * rot13_map - encodes with rot13 encryption
 * @c: char to possibly encode
 */
void rot13_map(char *c)
{
	int a[53] = {'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E',
		'f', 'F', 'g', 'G', 'h', 'H', 'i', 'I', 'j', 'J', 'k', 'K',
		'l', 'L', 'm', 'M', 'n', 'N', 'o', 'O', 'p', 'P', 'q', 'Q',
		'r', 'R', 's', 'S', 't', 'T', 'u', 'U', 'v', 'V', 'w', 'W',
		'x', 'X', 'y', 'Y', 'z', 'Z'};
	int b[53] = {'n', 'N', 'o', 'O', 'p', 'P', 'q', 'Q', 'r', 'R',
		's', 'S', 't', 'T', 'u', 'U', 'v', 'V', 'w', 'W', 'x', 'X',
		'y', 'Y', 'z', 'Z', 'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D',
		'e', 'E', 'f', 'F', 'g', 'G', 'h', 'H', 'i', 'I', 'j', 'J',
		'k', 'K', 'l', 'L', 'm', 'M'};
	int i;

	for (i = 0; i < 53; i++)
	{
		if (*c == a[i])
		{
			*c = b[i];
			return;
		}
	}
}
