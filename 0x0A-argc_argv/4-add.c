#include <stdio.h>
#include <stdlib.h>

/**
 * main - adds positive numbers
 * @argc: an integer representing the number of arguments passed to main
 * @argv: an array of pointers (pointer-to-pointer) to the string
 * representation of the command line arguments
 *
 * Return: 0, unless one of the numbers contain
 * non-digit symbols, then return 1
 */
int main(int argc, char *argv[])
{
	int i, j, sum = 0;

	/*if program is only called/launched...1*/
	if (argc == 1)
	{
		printf("%d\n", 0);
	}
	else
	{
		/*this loop ensures the processing of a variable*/
		/*number of arguments to main*/
		for (i = 1; i < argc; i++)
		{
			/*1...else, traverse the characters of each argument to check for*/
			/*those that contain symbols (xters) other than numeric ones (0 - 9)*/
			for (j = 0; *(argv[i] + j); j++)
			{
				if (((*(argv[i] + j) < 48) || (*(argv[i] + j) > 57)))
				{
					printf("%s\n", "Error");
					return (1);
				}
			}
			sum += atoi(argv[i]);
		}

		printf("%d\n", sum);
	}

	return (0);
}
