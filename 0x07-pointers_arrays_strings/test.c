#include <stdio.h>
#include <string.h>

int main(void)
{
	int arr[3] = {0x00, 0x03};
	int arr2[] = {0x03, 0x02, 0x04, 0x05};
	int sze, sze2;
	
	sze = (sizeof(arr) / sizeof(arr[0]));
	sze2 = (sizeof(arr2) / sizeof(arr2[0]));
	printf("sze: %d\n", sze);
	printf("sze2: %d\n", sze2);
	return (0);
}


