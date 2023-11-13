#include "main.h"

/**
 * _printf - a function that works like printf.
 * @format: the characters that will be printed on the std display.
 *
 * Return: count.
 */

int _printf(const char *format, ...)
{
	if (format == NULL)
	{
		return (1);
	}
	unsigned int i, spec, count = 0;
	unsigned int len = strlen(format);
	va_list args;

	va_start(args, format);

	for (i = 0; i < len; i++)
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			spec = '%';
			write(1, &spec, 1);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			print_char(va_arg(args, int));
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			print_string(va_arg(args, char *));
			i++;
		}
			else if (format[i] == '%' && format[i + 1] == 'd')
		{
			print_int(va_arg(args, int));
			i++;
		}
		else
			write(1, &format[i], 1);
		count++;
	}
	return (count);
}



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
