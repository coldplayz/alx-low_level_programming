#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file.
 * @filename: a pointer to the string
 * representing the name of the file to append text to.
 * @text_content: the NULL terminated string to add at the end of the file.
 *
 * Return: 1 on success and -1 on failure like if:
 * 1. filename is NULL
 * 2. the file does not exist or if you do not
 * have the required permissions to write the file.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int nw, fd;

	if (filename == NULL)
	{
		return (-1);
	}

	fd = open(filename, O_WRONLY | O_APPEND, 0600);
	if (fd < 0)
	{
		return (-1);
	}

	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}

	nw = write(fd, text_content, _strlen(text_content));
	if (nw < 0)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
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
