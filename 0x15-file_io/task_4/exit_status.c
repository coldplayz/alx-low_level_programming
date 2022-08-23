#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

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
