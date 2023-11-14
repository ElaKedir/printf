#include "main.h"

void print_buf(char buf[], int *i);

/**
 * _printf - Printf function
 * @format: format.
 * Return: count.
 */

int _printf(const char *format, ...)
{
	int i, printed = 0, count = 0;
	int flags, width, precision, size, i = 0;
	va_list list;
	char buf[BUFF_SIZE];

	if (!format)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i]; i++)
	{
		if (format[i])
		{
			buf[i++] = format[i];
			if (i == BUFF_SIZE)
				print_buf(buf, &i);
			count++;
		}
		else
		{
			print_buf(buf, &i);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buf,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			count += printed;
		}
	}

	print_buf(buf, &i);

	va_end(list);

	return (count);
}

/**
 * print_buf - Prints the contents of the buf if it exist
 * @buf: Array of chars
 * @i: Index at which to add next char, represents the length.
 */
void print_buf(char buf[], int *i)
{
	if (*i > 0)
		write(1, &buf[0], *i);

	*i = 0;
}

