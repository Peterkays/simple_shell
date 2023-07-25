#include "shell.h"

/**
  * _lyn_split - Split the line wrote in the console.
  * @lyn: Line wrote in console.
  * Return: An array with all words splited.
  */
char **_lyn_split(char *lyn)
{
	int size_ofbaffa = 64, place = 0;
	char **tokenn;
	char *token;

	tokenn = malloc(size_ofbaffa * sizeof(char *));
	if (!tokenn)
	{
		perror("star: allocation error\n");
		return (NULL);
	}

	tokenz = _stritknz(lyn, " \t\r\n\a");
	while (tokenz != NULL)
	{
		tokenn[place] = tokenz;
		place++;

		if (place >= size_ofbaffa)
		{
			size_ofbaffa += 64;
			tokenn = _smart_alloc(tokenn, size_ofbaffa - 64, size_ofbaffa * sizeof(char *));
			if (!tokenn)
			{
				perror("star: allocation error\n");
				return (NULL);
			}
		}
		tokenz = _stritknz(NULL, " \t\r\n\a");
	}
	tokenn[place] = NULL;
	return (tokenn);
}

