#include <stdio.h>
#include <string.h>

int main ()
{
	int a[] = {95, 66, 1, 2, 33, 456};
	int size;

	size = sizeof(a) / sizeof(int);
	printf("Size: %d\n", size);
	return (0);
}
