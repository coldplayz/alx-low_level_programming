#include <stdlib.h>
#include "function_pointers.h"

/**
 * print_name - prints string name
 * @name: a pointer to the name
 * @f: a pointer to a name-printing function
 */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
