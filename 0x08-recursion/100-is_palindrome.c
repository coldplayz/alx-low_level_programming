#include "main.h"

/**
 * is_it_palindrome - checks for palindromes
 * @s1: string to check, starting from first item
 * @s2: same as s1 but accessed in reverse
 * @n: number of times to compare both strings
 * @len: original length of string s1
 *
 * Return: 1 if string is palindrome, 0 otherwise
 */
int is_it_palindrome(char *s1, char *s2, int n, int len)
{
	if ((*s1 == *s2) && (*s1 == 0))
	{
		return (1);
	}

	if (n < (len / 2))
	{
		if (n == ((len / 2) - 1))
		{
			if (*s1 == *s2)
			{
				return (1);
			}
			else
			{
				return (0);
			}
		}

		if (*s1 != *s2)
		{
			return (0);
		}
		else
		{
			return (is_it_palindrome((s1 + 1), (s2 - 1), (n + 1), len));
		}
	}
	return (0);
}


/**
 * is_palindrome - checks for palindromic strings
 * @s: pointer to string to check
 *
 * Return: 1 if s is palindromic, 0 otherwise
 */
int is_palindrome(char *s)
{
	int n, str_index, len;

	n = 0;
	len = _strlen_recursion(s);
	str_index = (_strlen_recursion(s) - 1);

	return (is_it_palindrome(s, (s + str_index), n, len));
}


/**
 * _strlen_recursion - returns the length of a string
 * @s: string whose length to return
 *
 * Return: returns the length of a string
 */
int _strlen_recursion(char *s)
{
	if (*s == 0)
	{
		return (0);
	}

	return (1 + (_strlen_recursion(s + 1)));
}
