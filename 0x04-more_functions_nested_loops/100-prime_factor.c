#include <stdio.h>

/**
 * main - finds and prints greatest factor of a number
 *
 * Return: 0 always
 */
int main(void)
{
	long long max_factor, divisor = 2;

	long long n = 612852475143, divisor_limit = ((n / 2) + 1);

	while (divisor <= divisor_limit)
	{
		if (n % divisor == 0)
		{
			while (n % divisor == 0)
			{
				n /= divisor;
				max_factor = divisor;
			}
		}
		divisor++;
	}
	printf("%lld\n", max_factor);

	return (0);
}
