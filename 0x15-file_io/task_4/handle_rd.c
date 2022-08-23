#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

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
