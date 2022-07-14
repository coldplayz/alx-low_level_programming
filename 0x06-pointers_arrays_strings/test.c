#include <stdio.h>
#include <string.h>

int main () {
	char src[40];
	char dest[27] = "abcdefghijklmnopqrstuvwxyz";

	/*memset(dest, '\0', sizeof(dest));*/
	strcpy(src, "This is tutorialspoint");
	strncpy(dest, src, 10);

	printf("Final copied string : %s\n", dest);

	return(0);
}
