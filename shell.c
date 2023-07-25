#include "shell.h"


/**
 * main - The Simple shell file
 * @argc: the argument count
 * @argv: the argument value.
 * Return: Always 0 upon success.
 */

int main(__attribute__((unused)) int argc,
__attribute__((unused)) char **argv)
{

	/*Load config files, if any.*/

	/* Run command loop.*/
	_looper();

	/* Perform any shutdown/cleanup.*/

	return (0);
}

