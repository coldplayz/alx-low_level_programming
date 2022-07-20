#include "main.h"

/**
 * wildcmp - compares two strings for identity
 * @s1: pointer to main string to compare against
 * @s2: pointer to second string to compare with; with possible wild characters
 *
 * Return: returns 1 if the strings can be considered
 * identical, otherwise return 0
 */
int wildcmp(char *s1, char *s2)
{
	char *aa_val, *nna_val;

	if ((*s1 == *s2) || (*s2 == '*'))
	{
		if (*s2 == '*')
		{
			aa_val = after_asterisk(s2);
			if (aa_val == ((void *)0))
			{
				return (1);
			}
			nna_val = next_non_asterisk(s1, *aa_val);
			if (nna_val == ((void *)0))
			{
				return (0);
			}
			return (wildcmp((nna_val + 1), (aa_val + 1)));
		}
		else
		{
			if ((*s1 == 0) && (*s2 == 0))
			{
				return (1);
			}
			else
			{
				return (wildcmp((s1 + 1), (s2 + 1)));
			}
		}
	}
	else
	{
		return (0);
	}
}


/**
 * after_asterisk - returns the address of the next, non-asterisk
 * character of the parent string of s2
 * @s2: pointer to the current asterisk-valued address
 *
 * Return: a pointer to the next non '*' address, or null pointer if none
 */
char *after_asterisk(char *s2)
{
	if (*s2 != '*')
	{
		return (s2);
	}

	if (*s2 == 0)
	{
		return ((void *)0);
	}

	return (after_asterisk(s2 + 1));
}


/**
 * next_non_asterisk - returns the address of the next s1 character matching c
 * @s1: pointer to character
 * @c: char value for matching
 *
 * Return: pointer to the address of next character in s1 parent string
 * matching c, or null pointer if no match
 */
char *next_non_asterisk(char *s1, char c)
{
	if (*s1 == c)
	{
		return (s1);
	}

	if (*s1 == 0)
	{
		return ((void *)0);
	}

	return (next_non_asterisk((s1 + 1), c));
}
