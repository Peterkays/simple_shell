#include "shell.h"
/**
  * _begin - Launch the process to be excetute.
  * @arrgz: List of arguments passed from parsing.
  * Return: Always 1..
  */
int _begin(char **arrgz)
{
	int stts, pid;
	int sine = 0;

	arrgz = _check_way(arrgz, &sine);

	if (arrgz == NULL)
		return (1);

	pid = fork();
	if (pid == 0)
	{
		if (execve(arrgz[0], arrgz, environ) == -1)
		{
			perror("star");
		}
		if (sine == 1)
			free(arrgz[0]);
		return (-1);
	}
	else if (pid < 0)
	{
		perror("star");
		if (sine == 1)
			free(arrgz[0]);
		return (-1);

	}
	else
	{
		do {
			waitpid(pid, &stts, WUNTRACED);
		} while (!WIFEXITED(stts) && !WIFSIGNALED(stts));
	}
	if (sine == 1)
		free(arrgz[0]);
	return (1);
}

