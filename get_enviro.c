#include "shell.h"
#include <unistd.h>
/**
 * _get_envir - Finds variables in all environ var.
 * @the_nme: The name of environ var.
 * Return: Returns content into the environment variable.
 */

char *_get_envir(const char *the_nme)
{
	size_t lenth;
	char **pe;

	/* Gets NAME lenght size*/
	lenth = _stri_size((char *)the_nme);


	if (environ == NULL || the_nme[0] == '\0')
		return (NULL);

	lenth--;
	for (pe = environ; *pe != NULL; pe++)
	{
		if (!_stri_compa(*pe, the_nme, lenth) && (*pe)[lenth + 1] == '=')
			return (&(*pe)[lenth + 2]);
	}
	return (NULL);
}

