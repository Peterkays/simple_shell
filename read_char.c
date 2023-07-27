#include "shell.h"

/**
 * _ridchar - Reads a txt and prints it to the POSIX
 * Return: char
 */

int _ridchar(void)
{
	char bhafa[1];
	char *charct;
	int loctn_read;

	loctn_read = read(STDIN_FILENO, bhafa, 1);
	if (loctn_read > 0)
	{
		charct = bhafa;
		return (*charct);
	}

	if (loctn_read == -1)
		return (0);

	return (EOF);
}

