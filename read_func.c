#include "shell.h"

/**
 * _lyn_read -  Read command prompt.
 * Return: returns a pointer to the readed line
 */

char *_lyn_read(void)
{
	char *lyn = NULL;
	size_t size_ofbaffa = 0;
	ssize_t loctn;


	/* have _gt_lyn allocate the baffar. */
	loctn = _gt_lyn(&lyn, &size_ofbaffa, STDIN_FILENO);
	if (loctn == -1)
	{
		free(lyn);
		return (NULL);
	}
	return (lyn);
}

