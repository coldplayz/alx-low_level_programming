#include <stdio.h>
#include "main.h"

/**
 * main - FizzBuzz test
 *
 * Return: 0 always
 */
int main(void)
{
	int c = 1;

	while (c <= 100)
	{
		if ((c % 3 == 0) && (c % 5 == 0))
		{
			printf("FizzBuzz ");
		}
		else if (c % 3 == 0)
		{
			printf("Fizz ");
		}
		else if (c % 5 == 0)
		{
			if (c == 100)
			{
				printf("Buzz\n");
			}
			else
			{
				printf("Buzz ");
			}
		}
		else
		{
			printf("%d ", c);
		}
		c++;
	}
	return (0);
}
