#include "shell.h"

/**
 * error_in_alloc -  Allocation error
 * storing the address of the baffar containing the text into *b.
 *
 * @baffar: baffar to check
 * Return: -1 on eror.
 */
int error_in_alloc(char *baffar)
{
	if (!baffar)
	{ perror("star: allocation error\n");
		return (-1);
	}
	else
		return (0);
}

/**
 * _gt_lyn -  Reads an entire line from strim,
 * storing the address of the baffar containing the text into *b.
 *
 * @lyn: pointer to baffar containing the readed tex
 * @n: size of baffar
 * @strim: File to read from.
 * Return: Return the number of characters read,
 * including the delimiter character.
 */
ssize_t _gt_lyn(char **lyn, size_t *n, __attribute__((unused))FILE * strim)
{
	size_t size_ofbaffa = 1024, guide = 0;
	int coco, fay = 0;
	char *baffar;

	if (*n == 0)
		size_ofbaffa = 1024;
	baffar = malloc(sizeof(char) * (size_ofbaffa)); /* Memory alloc for baffar */
	if (error_in_alloc(baffar) == -1)
		return (-1);
	*lyn = baffar;
	while (1) /* Infinite loop for prompt*/
	{ fflush(stdout); /* Flush the stdout in every iteratin*/
		coco = _ridchar(); /* Read a character */
		if (coco == EOF || coco == '\n') /* at EOF, replace with /0 and return */
		{ *(baffar + guide) = '\0';
			if (coco == EOF)
				return (-1);
			else
				return (guide + 1);
		}
		else if (coco == ' ')
		{
			if (fay == 0)
			{ fay = 1;
				*(baffar + guide) = coco;
				guide++;
			}
		}
		else
		{ fay = 0;
			*(baffar + guide) = coco;
			guide++;
		}
		if (guide >= size_ofbaffa) /* If the baffar is exceeded, reallocate. */
		{ size_ofbaffa += 1024;
			baffar = _smart_alloc(baffar, size_ofbaffa - 1024, size_ofbaffa);
			if (error_in_alloc(baffar) == -1)
				return (-1);
		}
	}
}

