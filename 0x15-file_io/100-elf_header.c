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
	int fdelf;
	char *buff;

	(void)av;
	(void)ac;
	buff = malloc(1025);
	system("readelf -h ./a.out");

	fdelf = open("elf", O_RDONLY);

	read(fdelf, buff, 1024);

	write(1, buff, 100);

	return (0);
}
