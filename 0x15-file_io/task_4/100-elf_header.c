#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

/**
 * main - displays elf info
 * @ac: argument counter
 * @av: array of strings
 *
 * Return: always 0
 */
int main(int ac, char *av[])
{
	int fdelf, nr, nw;
	char *buff, *cmd_str;

	handle_args2(ac);
	cmd_str = relf(av[1]);
	if (cmd_str == NULL)
	{
		write(STDERR_FILENO, "Malloc failure in relf()\n", 25);
		exit(98);
	}

	buff = malloc(1025);
	if (buff == NULL)
	{
		write(STDERR_FILENO, "Malloc failure in main()\n", 25);
		exit(98);
	}
	buff[1024] = 0;

	system(cmd_str);
	exitstat();

	system("sed -i '9,10d' elf");
	system("sed -i '10,$d' elf");

	fdelf = open("elf", O_RDWR);
	handle_fd(fdelf);

	nr = read(fdelf, buff, 1024);
	handle_rderr(nr);

	nw = write(1, buff, _strlen(buff));
	handle_wrerr(nw);

	free(cmd_str);
	return (0);
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
 * relf - builds a readelf command-line string
 * @av1: the string representation of the
 * elf file to invoke the readelf command on. Supplied as an argument to main.
 *
 * Return: pointer to the command string, or NULL on malloc failure..
 */
char *relf(char *av1)
{
	int j, k, len = _strlen(av1), buff_size = 34 + len + 1;
	char *buff, str1[] = "readelf -h ", str2[] = " > elf ; echo $? > exit";

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
	for (; k < 23; ++j)
	{
		buff[j] = str2[k];
		k++;
	}
	buff[j] = 0;

	return (buff);
}


/**
 * exitstat - checks if the last run shell command exited with success (0).
 *
 * Return: 0 for exit success and -1 otherwise.
 */
int exitstat(void)
{
	char buff[4] = {0, 0, 0, 0};
	int fd;

	fd = open("exit", O_RDONLY);
	handle_fd(fd);

	read(fd, buff, 4);
	if (buff[0] == '0')
	{
		return (0);
	}
	else
	{
		close(fd);
		write(STDERR_FILENO, "Not an elf file\n", 16);
		exit(98);
	}

	return (0);
}


/**
 * handle_fd - handles open/creat errors
 * @fd: file descriptor returned by open/creat
 */
void handle_fd(int fd)
{
	if (fd < 0)
	{
		write(STDERR_FILENO, "Unable to open elf\n", 19);
		exit(98);
	}
}


/**
 * handle_rderr - handles read error
 * @nr: int returned by read() sys call.
 */
void handle_rderr(int nr)
{
	if (nr < 0)
	{
		write(STDERR_FILENO, "Unable to read from elf\n", 24);
		exit(98);
	}
}


/**
 * handle_wrerr - handles write error
 * @nw: int returned by write() sys call.
 */
void handle_wrerr(int nw)
{
	if (nw < 0)
	{
		write(STDERR_FILENO, "Unable to write from buffer\n", 28);
		exit(98);
	}
}


/**
 * handle_args - checks if number of main function
 * arguments equals 2
 * @ac: number if main arguments.
 * @av0: first argument string.
 */
void handle_args2(int ac)
{
	if (ac != 2)
	{
		write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
		exit(98);
	}
}
