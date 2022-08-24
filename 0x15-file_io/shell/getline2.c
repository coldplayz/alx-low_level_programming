#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

#define BUFF_SIZE 512;



ssize_t getline2(char **line, size_t *n, FILE *stream)
{
	char *buff;
	int c, i, bsize = BUFF_SIZE;
	ssize_t m = 0;

	buff = malloc(sizeof(char) * bsize);
	if (buff == NULL)
	{
		printf("Malloc error\n");
		exit(EXIT_FAILURE);
	}

	i = 0;
	c = getchar();
	while (c != '\n' || c != EOF)
	{
		buff[i] = c;
		++m;
		++i;

		if ((i + 1)>= bsize)
		{
			bsize += BUFF_SIZE;
			buff = realloc(buff, (sizeof(char) * bsize));
			if (buff = NULL)
			{
				printf("Realloc error\n");
				exit(EXIT_FAILURE);
			}
		}

		c = getchar();
	}
	buff[i++] = '\n';
	buff[i] = 0;

	*n = bsize;
	*line = buff;

	return (m);
}
