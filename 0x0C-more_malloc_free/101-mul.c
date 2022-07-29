#include <stdlib.h>
#include "main.h"

/**
 * main - multiplies two positive numbers
 * @ac: number of arguments passed to the program
 * @av: array of the arguments as strings
 * B
 *
 * Return: always 0
 */
int main(int ac, char **av)
{
	int i, j;
	char *prod;

	if (ac != 3)
	{
		_puts("Error");
		exit(98);
	}
	for (i = 1; i < ac; i++)
	{
		for (j = 0; *(av[i] + j); j++)
		{
			if ((*(av[i] + j) < 48) || (*(av[i] + j) > 57))
			{
				_puts("Error");
				exit(98);
			}
		}
	}
	prod = rev_mult_rev(av[1], av[2]);
	_puts(prod);

	return (0);
}


/**
 * _puts - prints a string using _putchar
 * @str: string to print
 */
void _puts(char *str)
{
	int i;

	for (i = 0; *(str + i); i++)
	{
		_putchar(*(str + i));
	}
	_putchar('\n');
}


/**
 * mult_rev_str - multiplies two [reversed] strings
 * @s1: pointer to one of the strings
 * @s2: pointer to the other string
 * @s1len: size of s1
 * @s2len: size of s2
 *
 * Return: an array of pointer to strings of numbers to sum up
 * as the result of the multiplication
 */
char **mult_rev_str(char *s1, char *s2, int s1len, int s2len)
{
	int i, j, k, m, i_res, carried = 0, written = 0;
	char *ptc, **res;

	res = malloc((sizeof(char *) * s1len) + (sizeof(char) * (s1len + s2len) * s1len) + (sizeof(char) * s1len));
	if (res == NULL)
	{
		return (NULL);
	}

	ptc = (char *)(res + s1len);
	for (i = 0; i < s1len; i++)
	{
		res[i] = ptc + (s1len + s2len + 1) * i;
	}

	for (i = 0; s1[i]; i++)
	{
		m = 0;
		written = 0;
		for (j = 0; s2[m]; j++)
		{
			if (j == 0)
			{
				for (; j < i; j++)
				{
					res[i][j] = '0';
				}
			}
			
			i_res = _atoi2(s1[i]) * _atoi2(s2[m]) + carried;
			m++;
			res[i][j] = (i_res % 10) + '0';
			written++;
			carried = i_res / 10;
		}
		if (carried != 0)
		{
			res[i][j] = carried + '0';
			j++;
			written++;
		}
		for (k = 0; k < ((s1len + s2len) - i - written); k++)
		{
			res[i][j] = '0';
			j++;
		}
		res[i][j] = 0;
		carried = 0;
	}
	return (res);
}


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
	return (0);
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
