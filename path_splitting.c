#include "shell.h"


/**
  * _split_way - Split the lyn of the path environment variable.
  * @lyn: Lyn with contents in paths..
  * @copy_lyn: Copy of lyn with contents in paths.
  * Return: An array with all paths split.
  */
char **_split_way(char *lyn, char *copy_lyn)
{
	int size_ofbaffa = 1024, place = 0;
	char **tokenn;
	char *tokenz;
	char *delimie = ":\r\n\a";

	tokenn = malloc(size_ofbaffa * sizeof(char *));
	if (!tokenn)
	{
		perror("star: allocation error\n");
		return (NULL);
	}
	_stri_dupl(copy_lyn, lyn);
	if (*copy_lyn == *delimie)
	{
		*copy_lyn = '\0';
		tokenn[place] = copy_lyn;
		place++;
	}
	tokenz = _stritknz(copy_lyn, delimie);
	while (tokenz != NULL)
	{
		tokenn[place] = tokenz;
		place++;

		if (place >= size_ofbaffa)
		{
			size_ofbaffa += 1024;
			tokenn = _smart_alloc(tokenn,
					size_ofbaffa - 1024, size_ofbaffa * sizeof(char *));
			if (!tokenn)
			{
				perror("star: allocation error\n");
				return (NULL);
			}
		}
		tokenz = _stritknz(NULL, delimie);
	}
	tokenn[place] = NULL;
	return (tokenn);
}

