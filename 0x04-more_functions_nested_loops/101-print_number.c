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
 * print_negative - prints negative integers
 * @n: negative integer
 */
void print_negative(int n)
{
	int power, low_lim = 10, high_lim = 100, length_flag = 1;
	int length_tracker = 2, last_low = 1000000000;

	_putchar('-');
	if (n <= -1 && n >= -9)
	{
		_putchar((n * -1) + '0');
		length_flag = 0;
	}
	while (length_flag)
	{
		if (low_lim == last_low)
		{
			length_flag = 0;
			while (length_tracker)
			{
				power = pwr(10, length_tracker - 1);
				_putchar(-(n / power) + '0');
				n = n % power;
				length_tracker--;
			}
		}
		else if (n <= -low_lim && n > -high_lim)
		{
			length_flag = 0;
			while (length_tracker)
			{
				power = pwr(10, length_tracker - 1);
				_putchar(-(n / power) + '0');
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
}

/**
 * print_positive - print positive integers
 * @n: positive integer to print
 */
void print_positive(int n)
{
	int power, low_lim = 10, high_lim = 100, length_flag = 1;
	int length_tracker = 2, last_high = 1000000000;

	if (n >= 0 && n <= 9)
	{
		_putchar(n + '0');
		length_flag = 0;
	}
	while (length_flag)
	{
		if (n >= low_lim && n < high_lim)
		{
			length_flag = 0;
			while (length_tracker)
			{
				power = pwr(10, length_tracker - 1);
				_putchar((n / power) + '0');
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
}
