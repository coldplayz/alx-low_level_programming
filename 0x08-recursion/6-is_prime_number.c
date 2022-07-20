#include "main.h"

/**
 * is_prime_number - indicates if n is a prime number or not
 * @n: integer number to check if a prime
 *
 * Return: returns 1 if the input integer is a prime number, otherwise return 0
 */
int is_prime_number(int n)
{
	int num = 2;

	return (_is_prime(n, num));
}


/**
 * _is_prime - checks whether a number is prime
 * @dividend: the integer number whose prime number status to check
 * @divisor: an  integer divisor (not smaller than 2) to start from
 *
 * Return: returns 1 if the input integer is a prime number, otherwise return 0
 */
int _is_prime(int dividend, int divisor)
{
	/*if divisor divides into dividend without remainder*/
	if (dividend <= 0 || dividend == 1)
	{
		return (0);
	}
	else if (!(dividend % divisor))
	{
		return (0);
	}

	/*divisor should not be incremented beyond half*/
	/*the value of dividend as, apart from 1 and itself,*/
	/*no number can be divided by a value greater than half its own*/
	if (divisor <= (dividend / 2))
	{
		return (_is_prime(dividend, (divisor + 1)));
	}
	else
	{
		return (1);
	}
}
