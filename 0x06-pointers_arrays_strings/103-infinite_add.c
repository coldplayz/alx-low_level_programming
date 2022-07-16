#include "main.h"
#include <stdio.h>

/**
 * strnumsum2int - add to integer characters and returns their sum
 * @c1: a character constant of form '0' to '9'
 * @c2: a character constant of form '0' to '9'
 *
 * Return: an integer sum of c1 and c2
 */
int strnumsum2int(char c1, char c2)
{
	int i, j, n1, n2;
	
	j = 0;
	for (i = 0; i < 10; i++)
	{
		if (c1 == (i + '0'))
		{
			n1 = i;
		}
		if (c2 == (j + '0'))
		{
			n2 = j;
		}
		j++;
	}

	return (n1 + n2);
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
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest
 * @dest: copy source to this buffer
 * @src: this is the source to copy
 * Return: copy of original source
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; i <= _strlen(src); i++)
		dest[i] = src[i];

	return (dest);
}

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
	int i, n, carry = 0;
	char *res, n1_copy[100], n2_copy[100];

	_strcpy(n1_copy, n1);
	_strcpy(n2_copy, n2);
	rev_string(n1_copy);
	rev_string(n2_copy);
	if ((_strlen(n1_copy)) >= (_strlen(n2_copy)))
	{
		return (str_adder(n1_copy, n2_copy, size_r));
	}
	else
	{
		return (str_adder(n2_copy, n1_copy, size_r));
	}
}

/**
 * str_adder - adds two integer character strings and returns one
 * @s1: pointer to string one
 * @s2: pointer to string two
 *
 * Return: pointer to a single string of integers characters
 */
char *str_adder(char *s1, char *s2, int size_r)
{
	int i, n, carry = 0;
	char res[100], n1_copy[100], n2_copy[100];

	_strcpy(n1_copy, s1);
	_strcpy(n2_copy, s2);
	rev_string(n1_copy);
	rev_string(n2_copy);
	for (i = 0; *(n1_copy + i); i++)
	{
		if ((*(n2_copy + i)) == '\0')
		{
			for (; *(n1_copy + i); i++)
			{
				n = strnumsum2int(*(n1_copy + i), '\0') + carry;
				res[i] = (n % 10) + '0';
				carry = (n / 10);
			}
		}
		else
		{
			n = strnumsum2int(*(n1_copy + i), *(n2_copy + i)) + carry;
			res[i] = (n % 10) + '0';
			carry = (n / 10);
		}
	}
	if ((carry != 0) && !(*(n1_copy + i)))
	{
		res[i] = carry + '0';
	}
	
	if (_strlen(res) <= size_r)
	{
		return (res);
	}
	else
	{
		for (i = 0; i < 100; i++)
		{
			printf("%c, ", res[i]);
		}
		printf("\n");
		return (0);
	}
}
