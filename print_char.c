#include "main.h"

/**
 * print_char - a function that prints characters.
 * @spec: the characters to be printed.
 *
 * Return: the printed characters.
 */

int print_char(int spec)
{
	return (write(1, &spec, 1));
}

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

/**
 * print_int - a function that prints intigers.
 * @spec: the intigers to be printed.
 *
 * Return: the printed intigers.
 */

int print_int(int spec)
{
	char buffer[20];
	int count = 0;
	int i = 0;

	if (spec == 0)
	{
		buffer[i++] = '0';
		write(1, buffer, 1);
		return (1);
	}

	if (spec < 0)
	{
		write(1, "-", 1);
		spec = -spec;
		count++;
	}

	while (spec > 0)
	{
		buffer[i++] = spec % 10 + '0';
		spec /= 10;
	}

	for (int j = i - 1; j >= 0; j--)
	{
		write(1, &buffer[j], 1);
		count++;
	}

	return (count);
}
