#include <stdio.h>

/**
 * main -
 * @argc: an integer representing the number of arguments passed to main
 * @argv: an array of pointers (pointer-to-pointer) to the string
 * representation of the command line arguments
 *
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	int i;
	(void)argc;

	for (i = 0; i < 3; i++)
	{
		printf("%c\n", *(argv[1] + i));
	}
	return (0);
}
