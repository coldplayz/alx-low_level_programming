#include <stdlib.h>
#include "main.h"

/**
 * argstostr - concatenates all program arguments
 * @ac: a count of all arguments passed to the program
 * @av: a pointer to the string representation of the arguments passed
 *
 * Return: a pointer to the first character of the concatenated string
 */
char *argstostr(int ac, char **av)
{
	int i, j, sum = 0, k = 0;
	char *ptc;

	if ((ac == 0) || (av == NULL))
	{
		return (NULL);
	}

	for (i = 0; i < ac; i++)
	{
		sum += _strlen(av[i]);
	}

	ptc = malloc((sum * sizeof(char)) + (ac * sizeof(char)) + (1 * sizeof(char)));
	if (ptc == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < ac; i++)
	{
		for (j = 0; *(av[i] + j); j++)
		{
			ptc[k] = *(av[i] + j);
			k++;
		}
		ptc[k] = '\n';
		k++;
	}
	ptc[k] = '\0';

	return (ptc);
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
