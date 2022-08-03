#include <string.h>
#include <stdlib.h>
#include "3-calc.h"
#include "function_pointers.h"
#define IFNULL(ptf, ptc) (((ptf) == NULL) || ((ptc) == NULL))
#define EXIT() exit(EXIT_SUCCESS)

/**
 * get_op_func - selects the correct
 * function to perform the operation asked by the user
 * @s: the operator passed as argument to the program, in string format
 *
 * Return:  a pointer to the function that
 * corresponds to the operator given as a parameter
 * Example: get_op_func("+") should return a pointer to the function op_add
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	if (s == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (i < 5)
	{
		if (strcmp(ops[i].op, s) == 0)
		{
			return (ops[i].f);
		}

		i++;
	}

	return (NULL);
}
