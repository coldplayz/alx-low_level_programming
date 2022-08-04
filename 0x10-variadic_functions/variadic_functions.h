#ifndef variadic_functions_h
#define variadic_functions_h

#include <stdarg.h>

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
int nvc(const char *const std_form, const char *const user_form);
int mi(const char *const std_form, char xter);
void print_any(va_list ap, char c, int valid, int count);
void print_all(const char * const format, ...);

#endif /*variadic_functions_h*/
