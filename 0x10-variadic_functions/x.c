#include <unistd.h>

char *c2s(char c, int i, int flag)
{
	char *ptc;
	char arr[2];

	ptc = arr;
	if (flag)
	{
		(void)c;
		ptc[0] = i + '0';
		ptc[1] = '\0';
	}
	else
	{
		(void)i;
		ptc[0] = c;
		ptc[1] = '\0';
	}

	return (ptc);
}

int main()
{
	int i = 5;
	char c[] = {'a', 'b'};
	char *s = "string";
	int b;
	int n = 8;
	int *p = &n;

	*(p++);

	b = write(1, &c, 1);
	write(1, c2s(0, n, 1), 1);

	return (0);
}
