#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * read_textfile -  reads a text file and
 * prints it to the POSIX standard output.
 * @filename: path to file to read and print
 * @letters: the number of letters it should read and print
 *
 * Return: the actual number of letters it could read and print, or 0 if:
 * 1. the file can not be opened or read
 * 2. filename is NULL
 * 3. write fails or does not write the expected amount of bytes
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t nr, nw;
	char *ptc;

	if (filename == NULL)
	{
		return (0);
	}

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		return (0);
	}

	ptc = malloc(letters + 1);
	if (ptc == NULL)
	{
		return (0);
	}
	ptc[letters] = 0;

	nr = read(fd, ptc, letters);
	if (nr < 0)
		return (0);
	nw = write(STDOUT_FILENO, ptc, nr);
	if (nr != nw)
		return (0);

	free(ptc);
	return (nw);
}
