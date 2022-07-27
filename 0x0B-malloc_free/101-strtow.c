#include <stdlib.h>
#include "main.h"
#include <stdio.h>

/**
 * strtow - splits a string into words
 * @str: string to be split into words
 *
 * Return: a pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	int i, *pti, sum = 0, count = 0, word_num = 0, pti_count = 0;
	int ptp_row_index = 0, last_ptp_row_index = 0, ptp_column_index = 0;
	char *ptc, **ptp;

	if ((str == NULL) || (*str == '\0'))
	{
		return (NULL);
	}
	for (i = 0; *(str + i); i++)
	{
		if (((*(str + i) != ' ') && ((str + i) == str)) || ((*(str + i) != ' ') && (*(str + i - 1) == ' ')))
		{
			word_num++;
		}
	}
	pti = malloc((word_num + 1) * sizeof(int));

	for (i = 0; *(str + i); i++)
	{
		if (*(str + i) == ' ')
		{
			/*for summing total number of words on encountering a space*/
			/*character, if the space character is not the first character*/
			/*of the string*/
			if (((str + i) != str) && (*(str + i - 1) != ' '))
			{
				sum += count + 1;
				if (pti_count == 0)
				{
					*(pti + pti_count) = 0;
					*(pti + pti_count + 1) = 0 + count + 1;
				}
				else
				{
					*(pti + pti_count + 1) = count + 1 + *(pti + pti_count);
				}
				pti_count++;
				count = 0;
			}
		}
		else
		{
			count++;
		}
	}
	sum += count + 1;
	*(pti + pti_count + 1) = count + 1 + *(pti + pti_count);

	ptp = malloc(((word_num + 1) * sizeof(char *)) + (sum * sizeof(char)));
	if (ptp == NULL)
	{
		return (NULL);
	}

	ptc = (char *)(ptp + (word_num + 1));
	for (i = 0; i < (word_num); i++)
	{
		ptp[i] = ptc + *(pti + i);
	}

	for (i = 0; *(str + i); i++)
	{
		if (*(str + i) == ' ')
		{
			if (((str + i) != str) && (*(str + i - 1) != ' '))
			{
				*(ptp[ptp_row_index] + ptp_column_index) = '\0';
				last_ptp_row_index = ptp_row_index;
				ptp_row_index++;
				ptp_column_index = 0;
			}
		}
		else
		{
			*(ptp[ptp_row_index] + ptp_column_index) = *(str + i);
			ptp_column_index++;
		}
	}
	if ((ptp_row_index == last_ptp_row_index) &&
			(*(ptp[ptp_row_index] + ptp_column_index) != '\0'))
	{
		*(ptp[ptp_row_index] + ptp_column_index) = '\0';
	}
	*(ptp + word_num) = NULL;

	return (ptp);
}
