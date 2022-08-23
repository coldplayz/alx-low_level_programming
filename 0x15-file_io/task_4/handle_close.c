#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

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
