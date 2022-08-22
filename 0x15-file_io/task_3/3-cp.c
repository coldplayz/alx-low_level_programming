#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

/**
 * main - copies the content of a file to another file.
 * @ac: the number of arguments
 * @av: an array of strings representing the arguments passed to main.
 *
 * Return: always 0.
 */
int main(int ac, char *av[])
{
	int fdrd, fdwr, nr, nw;
	char *buff;

	handle_args(ac, av[0]);
	buff = malloc(1025);
	if (buff == NULL)
	{
		exit(EXIT_FAILURE);
	}
	buff[1024] = 0;

	fdrd = open(av[1], O_RDONLY);
	if (fdrd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}

	fdwr = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fdwr < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
		handle_close(fdrd);
		exit(99);
	}
	handle_rdwr(fdrd, fdwr, buff);

	handle_close(fdrd);
	handle_close(fdwr);
	free(buff);

	return (0);
}


/**
 * handle_rdwr - reads from file referenced by fdrd to
 * file referenced by fdwr, handling any read/write errors.
 * @fdrd: file descriptor of file to read from.
 * @fdwr: file descriptor of file to write to.
 * @buff: buffer of 1 kb.
 */
void handle_rdwr(int fdrd, int fdwr, char *buff)
{
	int nr, nw;

	while (nr != 0)
	{
		nr = read(fdrd, buff, 1024);
		if (nr < 0)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
			handle_close(fdrd);
			handle_close(fdwr);
			exit(98);
		}

		nw = write(fdwr, buff, nr);
		if (nw < 0)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
			handle_close(fdrd);
			handle_close(fdwr);
			exit(99);
		}
	}
}


/**
 * handle_close - closes a file descriptor with proper error handling
 * @fd: file descriptor to close
 */
void handle_close(int fd)
{
	int n = close(fd);

	if (n < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}


/**
 * handle_args - checks if number of main function
 * arguments equals 3, and the first of them is equal to "cp"
 * @ac: number if main arguments.
 * @av0: first argument string.
 */
void handle_args(int ac, char *av0)
{
	if ((ac != 3) || (_strcmp(av0, "cp") != 0))
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * _strcmp - compares two strings for greatness
 * @s1: a string
 * @s2: a string
 *
 * Return: a negative integer if s1 is less than s2;
 * a positive integer if s1 is greater than s2, and;
 * 0 if both strings are the same
 */
int _strcmp(char *s1, char *s2)
{
	int i, len, shift = 0;

	for (len = 0; *(s1 + shift);)
	{
		len++;
		shift++;
	}

	for (i = 0; (i <= (len + 1)); i++)
	{
		if ((*(s1 + i) == '\0') && (*(s2 + i) == '\0'))
		{
			return (0);
		}
		else if ((*(s1 + i) == '\0') || (*(s2 + i) > *(s1 + i)))
		{
			/*return the difference between the two characters*/
			return ((*(s1 + i)) - (*(s2 + i)));
		}
		else if ((*(s2 + i) == '\0') || (*(s1 + i) > *(s2 + i)))
		{
			return ((*(s1 + i)) - (*(s2 + i)));
		}
	}
	return (0);
}
