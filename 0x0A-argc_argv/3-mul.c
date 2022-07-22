#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the product of two numbers
 * @argc: an integer representing the number of arguments passed to main
 * @argv: an array of pointers (pointer-to-pointer) to the string
 * representation of the command line arguments
 *
 * Return: 0, except when program does not recieve two
 * arguments in addition to the program mame
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("%s\n", "Error");
		return (1);
	}
	else
	{
		printf("%d\n", ((atoi(argv[1])) * (atoi(argv[2]))));
	}

	return (0);
}
