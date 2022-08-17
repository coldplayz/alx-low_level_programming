#ifndef variadic_functions_h
#define variadic_functions_h

#include <stdarg.h>

typedef struct std_form
{
	char c;
	int i;
	float f;
	char *s;
} std;

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
int nvc(const char *const std_form, const char *const user_form);
int mi(const char *const std_form, char xter);
void print_any(std structure, char c, int count);
void print_any_ext(std structure, char c, int count);
void print_all(const char * const format, ...);

#endif /*variadic_functions_h*/
