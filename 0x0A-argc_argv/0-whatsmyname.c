#include <stdio.h>

/**
 * main - prints the name of the program
 * @argc: an integer representing the number of arguments passed to main
 * @argv: an array of pointers (pointer-to-pointer) to the string
 * representation of the command line arguments
 *
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	(void)argc;

	printf("%s\n", argv[0]);

	return (0);
}
