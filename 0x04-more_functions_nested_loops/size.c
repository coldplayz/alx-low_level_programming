#include <stdio.h>

int main()
{
	printf("unsigned char: %zu\nchar: %zu\nsigned char: %zu\nshort: %zu\nunsigned short: %zu\nint: %zu\nunsigned int: %zu\nlong: %zu\nunsigned long: %zu\nlong long: %zu\nfloat: %zu\ndouble: %zu\nlong double: %zu\n", sizeof(unsigned char), sizeof(char), sizeof(signed char), sizeof(short), sizeof(unsigned short), sizeof(int), sizeof(unsigned int), sizeof(long), sizeof(unsigned long), sizeof(long long), sizeof(float), sizeof(double), sizeof(long double));

	return (0);
}
