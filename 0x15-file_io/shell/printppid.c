#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

int main (void)
{
	pid_t ppid;

	ppid = getppid();
	printf("%u\n", ppid);

	return (0);
}
