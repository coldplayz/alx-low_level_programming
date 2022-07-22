#include <stdio.h>

/**
 * main - prints the number of arguments passed into it
 * @argc: an integer representing the number of arguments passed to main
 * @argv: an array of pointers (pointer-to-pointer) to the string
 * representation of the command line arguments
 *
 * Return: always 0
 */
int main(int argc, char *argv[])

{
	(void)argv;

	printf("%d\n", argc - 1);

	return (0);
}
