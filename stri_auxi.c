#include "shell.h"

/**
 * _stri_size - Find the lenght of a string.
 * @s: string.
 * Return: lenght of the string.
 */
int _stri_size(char *s)
{
	int ctdr = 0;

	while (*(s + ctdr) != '\0')
	{
		ctdr++;
	}
	return (ctdr);
}

/**
 * _stri_cat - Concatent two strings.
 * @destin: string.
 * @stg: string.
 *
 * Return: Strings concated.
 */
char *_stri_cat(char *destin, char *stg)
{
	int w;
	int size = _stri_size(destin);

	for (w = 0; stg[w] != '\0'; w++)
	{
		destin[size + w] = stg[w];
	}
	destin[size + w] = '\0';

	return (destin);
}

/**
 * _stri_comp - Compare two strings..
 * @st1: string.
 * @st2: string.
 * Return: number < 0 if string 1 less string 2
 *         number = 0 if string 1 is equal to string 2
 *         number > 0 if string 1 is bigger than string 2
 */
int _stri_comp(char *st1, char *st2)
{
	int w = 0;

	while (st1[w] != '\0' && st2[w] != '\0')
	{
		if (st1[w] != st2[w])
		{
			return (st1[w] - st2[w]);
		}
		w++;
	}
	return (0);
}


/**
  * _stri_dupl - Print the same string.
  * @destin: array;
  * @stg: string;.
  *
  * Return: The string copiedi.
  */
char *_stri_dupl(char *destin, char *stg)
{
	int j, i = 0;

	while (*(stg + i) != '\0')
	{
		i++;
	}

	for (j = 0; j <= i; j++)
	{
		*(destin + j) = *(stg + j);
	}

	destin[j + 1] = '\0';
	return (destin);
}

/**
  * _stri_compa - String comaprison.
  * @st1: string 1
  * @st2: string 2
  * @n: number of bytes
  * Return: 0 if equal diff if different.
  */
int _stri_compa(const char *st1, const char *st2, size_t n)
{
	unsigned char usc1 = '\0';
	unsigned char usc2 = '\0';
	int nfo;

	if (n >= 4)
	{
		nfo = n >> 2;
		do {
			usc1 = (unsigned char) *st1++;
			usc2 = (unsigned char) *st2++;
			if (usc1 == '\0' || usc1 != usc2)
				return (usc1 - usc2);
			usc1 = (unsigned char) *st1++;
			usc2 = (unsigned char) *st2++;
			if (usc1 == '\0' || usc1 != usc2)
				return (usc1 - usc2);
			usc1 = (unsigned char) *st1++;
			usc2 = (unsigned char) *st2++;
			if (usc1 == '\0' || usc1 != usc2)
				return (usc1 - usc2);
			usc1 = (unsigned char) *st1++;
			usc2 = (unsigned char) *st2++;
			if (usc1 == '\0' || usc1 != usc2)
				return (usc1 - usc2);
		} while (--nfo > 0);
		n &= 3;
	}
	while (n > 0)
	{
		usc1 = (unsigned char) *st1++;
		usc2 = (unsigned char) *st2++;
		if (usc1 == '\0' || usc1 != usc2)
			return (usc1 - usc2);
		n--;
	}
	return (usc1 - usc2);
}

