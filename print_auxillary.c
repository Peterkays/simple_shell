#include "shell.h"

/**
  * _puts - prints
  * @stri: ptr to a char
  * Return: void
  */
void _puts(char *stri)
{
	int app = 0;

	while (stri[app] != '\0')
	{
		_putchar(stri[app]);
		app++;
	}
}

/**
  * _putchar - writes chars c to stdout
  * @c: The char to print
  *
  * Return: On success 1.
  * On error, -1 is returned, and errno is set appropriately.
  */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
  * _atoi - Change a str to a integer.
  * @q: String.
  * Return: Int into the string.
  */
int _atoi(char *q)
{
	int w = 0, sine = 0, nmb = 1;
	unsigned int ptc = 1, sma = 0;

	while (q[w])
	{
		if ((q[w] == '-' || q[w] == '+') && sine == 0)
		{
			if (q[w] == '-')
			{
				nmb *= -1;
			}
			else
			{
				nmb *= 1;
			}
		}
		else if (q[w] >= '0' && q[w] <= '9')
		{
			sine = 1;
		}
		else if (sine)
		{
			break;
		}

		w++;
	}

	w--;
	while (q[w] >= '0' && q[w] <= '9')
	{
		sma += (q[w] - '0') * ptc;
		ptc *= 10;
		w--;
	}

	return (sma * nmb);
}

