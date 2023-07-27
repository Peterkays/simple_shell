#include "shell.h"

/**
 * _lyn_read -  Read from the command prompt.
 * Return: a pointer to the readed line
 */

char *_lyn_read(void)
{
	char *lyn = NULL;
	size_t size_ofbaffa = 0;
	ssize_t loctn;

	loctn = _gt_lyn(&lyn, &size_ofbaffa, STDIN_FILENO);
	if (loctn == -1)
	{
		free(lyn);
		return (NULL);
	}
	return (lyn);
}

