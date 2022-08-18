#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: pointer to a string of 0 and 1 chars
 * 
 * Return: the converted number, or 0 if:
 * 1. there is one or more chars in the string b that is not 0 or 1
 * 2. b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
