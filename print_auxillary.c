#include "shell.h"

/**
  * _puts - print like puts function
  * @stri: pointer to a char
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
  * _putchar - writes the character c to stdout
  * @c: The character to print
  *
  * Return: On success 1.
  * On error, -1 is returned, and errno is set appropriately.
  */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
  * _atoi - Change a string to a integer.
  * @s: String.
  * Return: Integer into the string.
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

