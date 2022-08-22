#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
	int n, m, fd1, fd2, fd3, fd4;
	char ar1[10240];

	fd1 = open("m2.txt", O_RDWR | O_CREAT, 0700);

	fd2 = open("m.txt", O_RDWR);
	fd3 = open("/vagrant/Downloads/cp.c", O_RDONLY);
	fd4 = open("test.c", O_RDWR);

	n = read(fd3, ar1, 10240);
	m = write(fd4, ar1, strlen(ar1));
	printf("n: %d, m: %d\n", n, m);

	close(fd1);
	close(fd2);

	return (0);
}
