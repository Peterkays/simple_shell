#include "shell.h"

/**
 * _looper - Returns a ptr to new allocated memory space.
*/

void _looper(void)
{
	char *nputt;
	char **arrgz;
	int stts;
	int itr = 1, lenth;

	if (isatty(STDIN_FILENO) != 1)
		itr = 0;

	signal(SIGINT, signl_hadler);

	do {
		if (itr != 0)
		{
			/* Print lyn prompt. */
			lenth = _stri_size("IGetC#now$ ");

			write(STDOUT_FILENO, "IGetC#now$ ", lenth);
		}

		/*from promt line (nputt) */
		nputt = _lyn_read();
		if (nputt == NULL)
			return;

		arrgz = _lyn_split(nputt);
		if (arrgz == NULL)
		{
			free(nputt);
			return;
		}

		stts = _executing(arrgz, nputt);

		/* Free nputt and arguments. */
		free(nputt);
		free(arrgz);

	} while (stts == 1);
}

