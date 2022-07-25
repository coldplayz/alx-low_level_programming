
#include <stdlib.h>
#include "main.h"

/**
 * strtow - splits a string into words
 * @str: string to be split into words
 *
 * Return: a pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	int i, sum = 0, count = 0;
	char **ptp;

	if ((str == NULL) || (str == ""))
	{
		return (NULL);
	}
	for (i = 0; *(str + i); i++)
	{
		if (*(str + i) == ' ')
		{
			if ((*(str + i - 1) != ' ') && ((str + i) != str))
			{
				sum += count + 1;
				count = 0;
			}
		}
		else
		{
			count++;
		}
	}

	ptp = malloc((sum * sizeof(char)) + (2 * sizeof(char)));
	if (ptp == NULL)
	{
		return (NULL);
	}

	for (i = 0; *(str + i); i++)
	{
		if (*(str + i) == ' ')
		{
			if ((*(str + i - 1) != ' ') && ((str + i) != str))
			{
				*(ptp + i) = '\0';
			}
		}
		else
		{
			*(ptp + i) = *(str + 1);
		}
	}
	*(ptp + i) = '\0';
	*(ptp + i + 1) = NULL;

	return (ptp);
}
