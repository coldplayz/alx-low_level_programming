#include "main.h"

/**
 * rev_string - prints strings in reverse
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
