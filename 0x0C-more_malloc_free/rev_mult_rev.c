#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * rev_mult_rev - multiplies two [un-reversed] numbers in string format
 * @s1: pointer to one of the numeric strings
 * @s2: pointer to the other numeric strings
 *
 * Return: a pointer to the result
 */
char *rev_mult_rev(char *s1, char *s2)
{
	int i, len1 = _strlen(s1), len2 = _strlen(s2);
	char *s1cpy, *s2cpy, *ptc, **res;

	s1cpy = strdup2(s1);
	s2cpy = strdup2(s2);
	if ((s1cpy == NULL) || (s2cpy == NULL))
	{
		return (NULL);
	}

	rev_string(s1cpy);
	rev_string(s2cpy);

	res = mult_rev_str(s1cpy, s2cpy, len1, len2);

	ptc = res[0];
	rev_string(ptc);

	for (i = 0; i < (len1 - 1); i++)
	{
		ptc = rev_add_rev(ptc, res[i + 1], 1, 0);
	}

	free(s1cpy);
	free(s2cpy);
	free(res);

	return (ptc);
}
