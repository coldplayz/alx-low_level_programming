#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

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
