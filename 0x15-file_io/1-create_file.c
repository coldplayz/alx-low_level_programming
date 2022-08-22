#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

/**
 * create_file - creates anew file.
 * @filename: name of new file to create.
 * @text_content: a NULL terminated string to write to the file.
 *
 * Description: created file must have these permissions: rw-------.
 * If the file already exists, the permissions are not changed.
 * If the file already exists, it's truncated.
 * If text_content is NULL, an empty file is created.
 * Return: 1 on success, -1 on failure like:
 * 1. filename is NULL
 * 2. file can not be created
 * 3. file can not be written
 * 4. write “fails”
 */
int create_file(const char *filename, char *text_content)
{
	int nw, fd;

	if (filename == NULL)
	{
		return (-1);
	}

	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0600);
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
