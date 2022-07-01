#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - prints a random number each time
 *
 * Return: always zero
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	char description;

	if (n < 0)
	{
		description = "is positive";
	}
	else if (n == 0)
	{
		description = "is zero";
	}
	else
	{
		description = "is negative";
	}

	printf("%d %c\n", n, description);
	return (0);
}
