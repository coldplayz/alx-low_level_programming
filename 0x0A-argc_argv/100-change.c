#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the minimum number of coins to
 * make change for an amount of money
 * @argc: an integer representing the number of arguments passed to main
 * @argv: an array of pointers (pointer-to-pointer) to the string
 * representation of the command line arguments
 *
 * Return: 0, unless no number is supplied, then 1
 */
int main(int argc, char *argv[])
{
	int i, n, num_of_coins = 0;
	int denominations[5] = {25, 10, 5, 2, 1};

	if (argc != 2)
	{
		printf("%s\n", "Error");
		return (1);
	}

	n = atoi(argv[1]);
	if (n < 0)
	{
		printf("%d\n", 0);
	}
	else
	{
		for (i = 0; i < 5; i++)
		{
			if (n >= denominations[i])
			{
				num_of_coins += (n / (denominations[i]));
				n = n % (denominations[i]);
			}
		}
		printf("%d\n", num_of_coins);
	}

	return (0);
}
