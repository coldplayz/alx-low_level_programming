#include <stdio.h>

/**
 * main - prints type sizes
 *
 * Return: returns zero to end program successfully
 */
int main(void)
{
	int i = sizeof(int);
	char c = sizeof(char);
	long int li = sizeof(long int);
	long long int lli = sizeof(long long int);
	float tf = sizeof(float);

	printf("Size of a char: %d byte(s)\nSize of an int: %d byte(s)\nSize of a long int: %d byte(s)\nSize of a long long int: %d byte(s)\nSize of a float: %.0f byte(s)\n", c, i, li, lli, tf);
	return (0);
}
