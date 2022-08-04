#include <stdio.h>
#include <stdarg.h>

void pf(va_list ap)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		printf("%d\n", va_arg(ap, int));
	}
}

void vf(int n, ...)
{
	va_list ap;

	va_start(ap, n);
	pf(ap);
	va_end(ap);
	printf("%d\n", va_arg(ap, int));
}

int main()
{
	vf(4, 1, 2, 3, 4, 5);

	return (0);
}
