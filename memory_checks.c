#include "shell.h"

/**
 * _smart_alloc -  Re_allocates a memo using malloc and free.
 * @pntr: Pointers
 * @foma_size: Old size
 * @curnt_size: New size
 * Return: returns a pointer to the array
 */
void *_smart_alloc(void *pntr, unsigned int foma_size, unsigned int curnt_size)
{
	unsigned int w, low_size;
	char *newpntr;

	if (curnt_size == foma_size)
		return (pntr);

	if (pntr == NULL)
	{
		newpntr = malloc(curnt_size);
			if (newpntr == NULL)
				return (NULL);
			else
				return (newpntr);
	}
	else if (curnt_size == 0)
	{
		free(pntr);
		return (NULL);
	}

	if (foma_size > curnt_size)
		low_size = curnt_size;
	else
		low_size = foma_size;

	newpntr = malloc(curnt_size);
	if (newpntr == NULL)
		return (pntr);

	for (w = 0 ; w < low_size ; w++)
		*(newpntr + w) = *((char *)pntr + w);

	if (pntr != NULL)
		free(pntr);

	return (newpntr);
}

