/**
 * nvc - determines number of characters in user_form
 * that matches any of the characters in std_form
 * @std_form: a pointer to the standard format string
 * @user_form: a pointer to the user-defined format string
 *
 * Return: an int representing the number of matches
 */
int nvc(const char *const std_form, const char *const user_form)
{
	int i, j, count = 0;

	for (i = 0; user_form[i]; i++)
	{
		for (j = 0; std_form[j]; j++)
		{
			if (user_form[i] == std_form[j])
			{
				count++;
				break;
			}
		}
	}

	return (count);
}
