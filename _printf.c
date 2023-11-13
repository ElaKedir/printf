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
