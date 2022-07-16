#include "main.h"

/**
 * pwr - computes the power of an integer
 * @base: an integer base
 * @index: an integer power to raise the base to
 *
 * Return: an integer
 */
int pwr(int base, int index)
{
	int counter = 0, power = 1;

	while (counter < index)
	{
		power *= base;
		counter++;
	}

	return (power);
}

/**
 * print_number - prints any integer
 * @n: integer argument
 */
void print_number(int n)
{
	if (n < 0)
	{
		print_negative(n);
	}
	else
	{
		print_positive(n);
	}
}

/**
 * int2str - converts an integer to a string
 * @n: positive integer to convert
 *
 * Return: a pointer to a string
 */
char * int2str(int n)
{
	int power, low_lim = 10, high_lim = 100, length_flag = 1;
	int length_tracker = 2, last_high = 1000000000, arr_index = 0, j = 0;
	char num[];

	if (n >= 0 && n <= 9)
	{
		num[j] = (n + '0');
	}
	while (length_flag)
	{
		if (n >= low_lim && n < high_lim)
		{
			length_flag = 0;
			while (length_tracker)
			{
				power = pwr(10, length_tracker - 1);
				num[arr_index] = (n / power) + '0';
				arr_index++;
				n = n % power;
				length_tracker--;
			}
		}
		else
		{
			low_lim = low_lim * 10;
			high_lim = low_lim * 10;
			length_tracker++;
		}
	}

	return (num);
}
