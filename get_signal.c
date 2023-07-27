#include "shell.h"

/**
  * signl_hadler - Signal handling.
  * @sg: The signal.
  */

void signl_hadler(int sg)
{
	(void)sg;
	_putchar('\n');
	write(STDOUT_FILENO, "IGetC#now$ ", 2);
	fflush(stdout);

}

