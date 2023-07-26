#include "shell.h"
#include <unistd.h>
/**
 * _get_envir - Find a variable in all environment variables.
 * @the_nme: Name of the environment variable.
 * Return: All the content into the environment variable.
 */

char *_get_envir(const char *the_nme)
{
	size_t lenth;
	char **pe;

	/* Get NAME lenght*/
	lenth = _stri_size((char *)the_nme);


	if (enviro == NULL || the_nme[0] == '\0')
		return (NULL);

	lenth--;
	for (pe = enviro; *pe != NULL; pe++)
	{
		if (!_stri_compa(*pe, the_nme, lenth) && (*pe)[lenth + 1] == '=')
			return (&(*pe)[lenth + 2]);
	}
	return (NULL);
}

