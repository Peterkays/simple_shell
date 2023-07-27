#include "shell.h"

/**
 * error_in_alloc2 -  Error in allocatiorn
 * storing the address of the baffar with the text into *b.
 *
 * @baffar: baffar to check
 * Return: -1 on erorr.
 */
int error_in_alloc2(char *baffar)
{
	if (!baffar)
	{ perror("star: allocation error\n");
		return (-1);
	}
	else
		return (0);
}

/**
 * error_in_alloc1 -  Error in allocation.
 * storing the address of the baffar with the text into *b.
 * @destin_way: destin way
 * @baffar: baffar to check
 * Return: -1 on eror.
 */
int error_in_alloc1(char *baffar, char *destin_way)
{
if (!baffar)
	{ free(destin_way);
		perror("star: allocation error\n");
		return (-1);
	}
		return (0);
}

/**
  * _check_way - Split lyn wrote in the command.
  * @arrgz: yne wrote in command.
  * @sine: sine
  * Return: String with the file path.
  */

char **_check_way(char **arrgz, int *sine)
{
	char *way, **tokenn_way, *destin_way, *copy_lyn;
	int j, k;

	for (k = 0; *(arrgz[0] + k) != '\0'; k++)
	{
		if (*(arrgz[0] + k) == '/')
			return (arrgz);
	}
	destin_way = malloc(sizeof(char) * 1024); /*Memo alloc for comp path */
	if (error_in_alloc2(destin_way) == -1)
		return (NULL);
	way = _get_envir("PATH"); /*  Finds path from environ with diff paths */
	copy_lyn = malloc((_stri_size(way) + 1) * sizeof(char *));
	if (error_in_alloc1(copy_lyn, destin_way) == -1)
		return (NULL);
	tokenn_way = _split_way(way, copy_lyn); /* Finds array of pntr to pos paths*/
	if (tokenn_way == NULL)
	{ free(copy_lyn);
		return (NULL);
	}
	for (j = 0; *(tokenn_way + j) != NULL; j++)
	{ _stri_dupl(destin_way, *(tokenn_way + j));
		if (*destin_way != '\0')
			_stri_cat(destin_way, "/");
		else
			_stri_cat(destin_way, "./");
		_stri_cat(destin_way, arrgz[0]);
		if (access(destin_way, X_OK) != -1) /* verify acces rights */
		{ arrgz[0] = destin_way;
			*sine = 1;
			free(copy_lyn);
			free(tokenn_way);
			return (arrgz);
		}
	}
	free(destin_way);
	free(tokenn_way);
	free(copy_lyn);
	perror("star");
	return (NULL);
}

