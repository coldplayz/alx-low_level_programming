#include "main.h"

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: integer number to find the square root of
 *
 * Return: returns the natural square root of a number, or -1 if none
 */
int _sqrt_recursion(int n)
{
	int num = 0;

	return (_sqrt(n, num));
}


/**
 * _sqrt - returns natural square root
 * @dividend: the integer number whose square root to find
 * @divisor: the number to potentially match the required square root
 *
 * Return: returns the natural square root of a number, or -1 if none
 */
int _sqrt(int dividend, int divisor)
{
	/*ref1*/
	if (dividend == 4)
	{
		return (2);
	}
	else if (dividend == 9)
	{
		return (3);
	}

	/*once you have a perfect square*/
	if (((dividend / divisor) == divisor) && !(dividend % divisor))
	{
		return (divisor);
	}

	/*ensures that we recurse through*/
	/*dividend/4 divisors, at most (all thanks to ref1*/
	if (divisor <= (dividend / 4))
	{
		return (_sqrt(dividend, (divisor + 1)));
	}
	else
	{
		return (-1);
	}
}
