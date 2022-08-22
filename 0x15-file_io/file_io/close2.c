#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * close2 - closes multiple file descriptors
 * @n: the number of file descriptor-arguments
 */
void close2(int n, ...)
{
	int i, fd;
	va_list args;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		fd = va_arg(args, int);
		close(fd);
	}

	va_end(args);
}
