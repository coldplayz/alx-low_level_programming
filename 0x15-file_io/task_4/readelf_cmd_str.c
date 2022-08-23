#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

/**
 * relf - builds a readelf command-line string
 * @av1: the string representation of the
 * elf file to invoke the readelf command on.
 *
 * Return: pointer to the command string, or NULL on malloc failure..
 */
char *relf(char *av1)
{
	int j, k, len = _strlen(av1), buff_size = 17 + len + 1;
	char *buff, str1[] = "readelf -h ", str2[] = " > elf";

	buff = malloc(buff_size);
	if (buff == NULL)
	{
		return (NULL);
	}

	for (j = 0; j < 11; ++j)
	{
		buff[j] = str1[j];
	}

	k = 0;
	for (; k < len; ++j)
	{
		buff[j] = av1[k];
		++k;
	}

	k = 0;
	for (; k < 6; ++j)
	{
		buff[j] = str2[k];
		k++;
	}
	buff[j] = 0;

	return (buff);
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
