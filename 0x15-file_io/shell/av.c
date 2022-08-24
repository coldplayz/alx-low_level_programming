#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

int main(int ac, char **av)
{
	int i;

	i = 0;
	while (av[i])
	{
		printf("%s\n", av[i]);
		++i;
	}

	return (0);
}
