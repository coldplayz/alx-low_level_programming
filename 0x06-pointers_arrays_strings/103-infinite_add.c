#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * infinite_add - adds two integer strings of any length
 * and store result in a specified buffer, if large enough
 * @n1: integer string
 * @n2: integer string
 * @r: storage buffer
 * @size_r: size of storage buffer
 *
 * Return: pointer to r, if it is large enough to store the result, otherwise 0
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	char *ptc;

	ptc = rev_add_rev(n1, n2, 1, 1);
	if ((_strlen(ptc) + 1) > size_r)
	{
		return (0);
	}

	r = ptc;

	return (r);
}


/**
 * rev_add_rev - adds two [un-reversed] numeric strings. Undefined symbols in libuf.a
 * strings and returns the result
 * @s1: pointer to numeric string
 * @s2: pointer to numeric string
 * @revs1: an integer flag indicating whether, or not, to reverse s1
 * @revs2: an integer flag indicating whether, or not, to reverse s2
 *
 * Return: pointer to result string
 */
char *rev_add_rev(char *s1, char *s2, int revs1, int revs2)
{
	int len1 = _strlen(s1), len2 = _strlen(s2);
	char *s1cpy, *s2cpy, *res;

	s1cpy = strdup2(s1);
	s2cpy = strdup2(s2);
	if ((s1cpy == NULL) || (s2cpy == NULL))
	{
		return (NULL);
	}

	if (revs1)
		rev_string(s1cpy);
	if (revs2)
		rev_string(s2cpy);

	if (len1 > len2)
	{
		res = add_rev_str(s1cpy, s2cpy, len1);
	}
	else
	{
		res = add_rev_str(s2cpy, s1cpy, len2);
	}

	rev_string(res);

	free(s1cpy);
	free(s2cpy);

	return (res);
}


/**
 * add_rev_str - adds two numeric strings together
 * @str1: pointer to the longer string
 * @str2: pointer to the shorter, or equal-length, string
 * @len1: length, or size, of str1
 *
 * Return: a pointer to the result
 */
char *add_rev_str(char *str1, char *str2, int len1)
{
	int i, i_res, carried = 0;
	char *res;

	res = malloc(len1 + 2);
	if (res == NULL)
	{
		return (NULL);
	}

	for (i = 0; str1[i]; i++)
	{
		if (!(str2[i]))
		{
			i_res = _atoi2(str1[i]) + 0 + carried;
			res[i] = (i_res % 10) + '0';
			carried = i_res / 10;
		}
		else
		{
			i_res = _atoi2(str1[i]) + _atoi2(str2[i]) + carried;
			res[i] = (i_res % 10) + '0';
			carried = i_res / 10;
		}
	}
		
	if (carried != 0)
	{
		res[i] = carried + '0';
		res[i + 1] = '\0';
	}
	else
	{
		res[i + 1] = '\0';
	}

	return (res);
}


/**
 * _atoi2 - converts character constants from
 * 0 to 9 to actual integers
 * @c: a character constant of form '0' to '9'
 *
 * Return: an integer
 */
int _atoi2(char c)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		if (c == (i + '0'))
		{
			return (i);
		}
	}
	return (i);
}


/**
 * _strlen - returns the length of a string
 * @s: pointer to char type
 *
 * Return: an integer length of the argument
 */
int _strlen(char *s)
{
	int len, shift = 0;

	for (len = 0; *(s + shift);)
	{
		len++;
		shift++;
	}

	return (len);
}


/**
 * rev_string - reverses the order of a string
 * @s: string pointer
 */
void rev_string(char *s)
{
	int counter = 0, temp, len, low_index = 0, shift = 0;

	/*move from first character of array s to null...*/
	/*...to get the array length*/
	for (; *(s + shift);)
	{
		shift++;
	}
	len = shift;

	/*move from last character of array s to first, replacing...*/
	/*...the characters with first to last characters respectively*/
	for (shift--; counter < (len / 2); shift--)
	{
		temp = *(s + shift);
		*(s + shift) = s[low_index];
		s[low_index] = temp;
		low_index++;
		counter++;
	}
}


/**
 * strdup2 - copies a string to newly allocated memory.
 * @str: pointer string to make a duplicate of.
 *
 * Return: a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 */
char *strdup2(char *str)
{
	int i, j;
	char *ptc;

	if (str == NULL)
	{
		return (NULL);
	}

	j = _strlen(str);
	ptc = malloc((j + 1) * sizeof(char));
	if (ptc == NULL)
	{
		return (NULL);
	}

	/*copy all the xters of str, including '\0'*/
	for (i = 0; i <= j; i++)
	{
		*(ptc + i) = *(str + i);
	}

	return (ptc);
}
