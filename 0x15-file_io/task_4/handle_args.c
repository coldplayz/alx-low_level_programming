#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

/**
 * handle_args - checks if number of main function
 * arguments equals 2
 * @ac: number if main arguments.
 * @av0: first argument string.
 */
void handle_args(int ac)
{
	if (ac != 2)
	{
		write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
		exit(98);
	}
}
