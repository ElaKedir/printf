#include "main.h"

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
