#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

int main(void)
{
	char *line = NULL;
	size_t n = 0;

	printf("$ ");
	if (getline2(&line, &n, stdin) < 0)
	{
		printf("Error getting line from stdin\n");
		exit(EXIT_FAILURE);
	}

	printf("%s", line);

	return (0);
}
