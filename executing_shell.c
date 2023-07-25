#include "shell.h"

/**
  * builtin_func - Redirect to builtin functions.
  * @builtin_func: Redirect to builtin functions.
  * Return: 1 if _hellp works, 0 if exit works.
  */

int (*builtin_func[])(char **arrgz, char *nputt) = {
	&_cdir,
	&_hellp,
	&star_exit,
	&_envyr,
};

/**
  * _executing - Execute builtin process.
  * @arrgz: List of arguments passed from parsing.
  * @nputt: Nputt line for free.
  * Return: _begin(arrgz).
  */
int _executing(char **arrgz, char *nputt)
{
	char *builtin_stri[] = {"cdir", "hellp", "exit", "envyr"};
	int w;

	if (arrgz[0] == NULL)
		return (1);

	if (_stri_comp(arrgz[0], "set_envi") == 0)
		return (_set_envi(arrgz[1], arrgz[2]));

	for (w = 0; w < 4; w++)
	{
		if (_stri_comp(arrgz[0], builtin_stri[w]) == 0)
			return ((*builtin_func[w])(arrgz, nputt));
	}
	return (_begin(arrgz));
}

