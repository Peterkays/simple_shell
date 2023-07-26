#include "shell.h"
#include <unistd.h>

/**
  * _cdir - Change the directory.
  * @arrgz: List of arguments passed from parsing.
  * @nputt: Nputt line for free.
  * Return: 1 if works.
  */
int _cdir(char **arrgz, __attribute__((unused)) char *nputt)
{

	if (arrgz[1] == NULL)
	{
		if (chdir(_get_envir("HOME")) != 0)
		{
			perror("star:");
		}
	}
	else
	{
		if (chdir(arrgz[1]) != 0)
		{
			perror("star:");
		}
	}
	return (1);
}


/**
  * _hellp - Display the help about a command.
  * @arrgz: List of arguments passed from parsing.
  * @nputt: Nputt line for free.
  * Return: 1 if works.
  */
int _hellp(__attribute__((unused)) char **arrgz,
		__attribute__((unused)) char *nputt)
{
	int w;
	char *builtin_stri[] = {"cdir", "hellp", "exit"};

	for (w = 0; w < 3; w++)
	{
		write(STDOUT_FILENO, builtin_stri[w], _stri_size(builtin_stri[w]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}

/**
  * star_exit - Exit to the shell.
  * @arrgz: List of arguments passed from parsing.
  * @nputt: Nputt line for free.
  * Return: 0 if works.
  */
int star_exit(__attribute__((unused)) char **arrgz, char *nputt)
{
	int vah;

	if (arrgz[1] == NULL)
		return (0);

	vah = _atoi(arrgz[1]);

	if (vah < 0)
	{
		perror("star:");
		return (1);
	}
	else if (vah == 0)
	{
		return (0);
	}
	else if (vah >= 256)
	{
		free(nputt);
		free(arrgz);
		exit(vah - 256);
	}
	else
	{
		free(nputt);
		free(arrgz);
		exit(vah);
	}
}

/**
  * _envyr - Display the enviro in the shell.
  * @arrgz: List of arguments passed from parsing.
  * @nputt: Nputt line for free.
  * Return: 1 if works.
  */
int _envyr(__attribute__((unused)) char **arrgz,
		__attribute__((unused)) char *nputt)
{
	int w = 0;

	while (enviro[w] != 0)
	{

		_puts(enviro[w]);
		_puts("\n");
		w++;
	}
	return (1);
}

/**
  * _set_envi - Set a enrinment variable.
  * @the_nme:Name of the variable
  * @its_valu: Value in the variable.
  * Return: 1 if works.
  */
int _set_envi(char *the_nme, char *its_valu)
{
	char *tmp, fresh_var[1024];
	char **pe = enviro;
	char **ve;
	int cntr = 0, i;

	if (its_valu == NULL)
	{
		perror("star:");
	}
	tmp = _get_envir(the_nme);
	if (tmp != NULL)
	{
		_stri_dupl(tmp, its_valu);
	}
	else
	{
		while (pe[cntr] != NULL)
		{
			cntr++;
		}
		cntr += 2;
		ve = malloc(cntr * sizeof(char *));
		for (i = 0; pe[i] != NULL; i++)
		{
			ve[i] = pe[i];
		}
		_stri_cat(fresh_var, the_nme);
		_stri_cat(fresh_var, "=");
		_stri_cat(fresh_var, its_valu);
		ve[i] = fresh_var;
		ve[++i] = NULL;
		enviro = ve;
		free(pe);
	}

	return (1);
}

