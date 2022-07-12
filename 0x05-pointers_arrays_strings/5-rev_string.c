#include "main.h"

/**
 * rev_string - prints strings in reverse
 * @s: string pointer
 */
void rev_string(char *s)
{
	int max_index = 0, temp_index = _strlen(s), shift = 0;
	char temp[temp_index];

	/*move from first character of array s to null, copying...*/
	/*...array s into array temp*/
	for (; *(s + shift); (s + shift))
	{
		*(temp + shift) = *(s + shift);
		shift++;
		max_index++;
	}
	temp_index = 0;

	/*move from last character of array s to first, replacing...*/
	/*...the characters with first to last characters of array temp*/
	for (shift--; max_index > 0; shift--)
	{
		*(s + shift) = temp[temp_index];
		temp_index++;
		max_index--;
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

	for (len = 0; *(s + shift); (s + shift))
	{
		len++;
		shift++;
	}

	return (len);
}
