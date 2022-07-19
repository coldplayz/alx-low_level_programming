#include "main.h"
#include <stdio.h>

/**
 * set_string -  sets the value of a pointer to a char
 * @s: a pointer to a pointer
 * @to: the char to change the pointer to
 */
void set_string(char **s, char *to)
{
	*s = to;
}
