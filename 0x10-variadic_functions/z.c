#include <stdio.h>

/**
 * mi - finds the index, in std_form, that xter first finds a match
 * @std_form: a pointer to the string pattern
 * @xter: the character to match
 *
 * Return: a non-negative integer representing
 * the matching index in std_form; or -1 if no match is found
 */
int mi(const char *const std_form, char xter)
{
	int i;

	for (i = 0; std_form[i]; i++)
	{
		if (std_form[i] == xter)
		{
			return (i);
		}
	}

	return (-1);
}


int main()
{
	int i, j, count = 0;
	char ac[] = {'H', 'a'};
	char *ac2 = "cifs";
	char *format = "ceis";

	for (i = 0; i < 3; i++)
	{
		switch (ac[0])
		{
			case 0:
				printf("zero\n");
				continue;
			case 'H':
				printf("one\n");
			case 2:
				printf("two\n");
		}
	}

	if ("c"[0] == 'c')
	{
		printf("Worked!\n");
	}
	else
	{
		printf("Try again\n");
	}

	for (i = 0; format[i]; i++)
	{
		for (j = 0; ac2[j]; j++)
		{
			if (format[i] == ac2[j])
			{
				count++;
				break;
			}
		}
	}
	printf("index: %d\n", mi(ac2, 'm'));

	return (0);
}
