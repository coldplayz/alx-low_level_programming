#include <stdlib.h>
#include "function_pointers.h"
#define IFNULL(ptf, ptc) (((ptf) == NULL) || ((ptc) == NULL))
#define EXIT() exit(EXIT_SUCCESS)

/**
 * op_add - adds two integers
 * @a: an integer
 * @b: an integer
 *
 * Return: an integer sum
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - subtracts two integers
 * @a: an integer
 * @b: an integer
 *
 * Return: an integer difference
 */
int op_sub(int a, int b)
{
	return (a - b);
}


/**
 * op_mul - multiplies two numbers
 * @a: an integer
 * @b: an integer
 *
 * Return: an integer product
 */
int op_mul(int a, int b)
{
	return (a * b);
}


/**
 * op_div - divides two integers
 * @a: an integer
 * @b: an integer
 *
 * Return: an integer quotient
 */
int op_div(int a, int b)
{
	return (a / b);
}


/**
 * op_mod - gets the remainder of integer division
 * @a: an integer
 * @b: an integer
 *
 * Return: the remainder of integer division
 */
int op_mod(int a, int b)
{
	return (a % b);
}
