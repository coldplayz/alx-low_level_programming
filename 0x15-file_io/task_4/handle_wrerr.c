#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

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
