#include "main.h"

/**
 * print_string - a function that prints a string of characters.
 * @spec: the string of characters to be printed.
 *
 * Return: the printed string of characters.
 */

int print_string(char *spec)
{
	if (spec == NULL)
	{
		return (1);
	}
	unsigned int i, count = 0;
	unsigned int len = strlen(spec);

	for (i = 0; i < len; i++)
	{
		print_char((int)spec[i]);
		count++;
	}
	return (count);
}
