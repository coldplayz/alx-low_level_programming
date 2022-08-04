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
