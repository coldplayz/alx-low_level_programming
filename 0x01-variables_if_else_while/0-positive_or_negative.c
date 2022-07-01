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
	char description;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	if (n < 0)
	{
		(char)description = "is positive";
	}
	else if (n == 0)
	{
		(char)description = "is zero";
	}
	else
	{
		(char)description = "is negative";
	}

	printf("%d %c\n", n, description);
	return (0);
}
