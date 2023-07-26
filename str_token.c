#include "shell.h"

/**
  * _stri_ptn - Find the positing where the delimie is found in the string.
  * @sy: String.
  * @delimie: Delimiter.
  * Return: the place in the string.
  */
int _stri_ptn(char *sy, const char *delimie)
{
	int cntr = 0, ii;

	while (*sy)
	{
		for (ii = 0; delimie[ii] != '\0'; ii++)
		{
			if (*sy == delimie[ii])
				return (cntr);
		}
		cntr++;
		sy++;
	}
	return (cntr);
}

/**
  * _strieq_ptn - Find the positing until the delimie is equal to the string.
  * @ss: String.
  * @delimie: Delimiter.
  * Return: the place when delimie is different to the string.
  */

int _strieq_ptn(char *ss, const char *delimie)
{
	int w;

	for (w = 0; (ss[w] == delimie[w]) && (ss[w] != '\0' &&
				delimie[w] != '\0'); w++)
	{
		;
	}
	return (w);
}
/**
  * _stritknz_r - Find the first token in a string until the dilimiter
  *             and save the rest of the string in accept_stri.
  * @s: String.
  * @delimie: Delimiter.
  * @accept_stri: The rest of the string.
  * Return: First word tokenized.
  */
char *_stritknz_r(char *s, const char *delimie, char **accept_stri)
{
	char *finish;

	if (s == NULL)
		s = *accept_stri;

	if (*s == '\0')
	{
		*accept_stri = s;
		return (NULL);
	}

	s += _strieq_ptn(s, delimie);

	if (*s == '\0')
	{
		*accept_stri = s;
		return (NULL);
	}
	finish = s + _stri_ptn(s, delimie);

	if (*finish == '\0')
	{
		*accept_stri = finish;
		return (s);
	}

	*finish = '\0';
	*accept_stri = finish + 1;
	return (s);
}
/**
  * _stritknz - Tokenize a string in words separated by a delimiter.
  * @s: String.
  * @delimie: Delimiter.
  * Return: Word tekenized.
  */

char *_stritknz(char *s, const char *delimie)
{
	static char *older;

	return (_stritknz_r(s, delimie, &older));
}

