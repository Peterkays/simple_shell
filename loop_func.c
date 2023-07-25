#include "shell.h"

/**
 * _looper - Returns a pointer to a newly allocated space in memory
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
			/* Print prompt line. */
			lenth = _stri_size("IGetC#now$ ");
			
			write(STDOUT_FILENO, "IGetC#now$ ", lenth);
		}

		/*Read from promt line (nputt) */
		nputt = _lyn_read();
		if (nputt == NULL)
			return;

		/* Split readed nputt into arguments. */
		arrgz = _lyn_split(nputt);
		if (arrgz == NULL)
		{
			free(nputt);
			return;
		}

		/* Execute according to arguments. */
		stts = _executing(arrgz, nputt);

		/* Free nputt and arguments. */
		free(nputt);
		free(arrgz);

	} while (stts == 1);
}

