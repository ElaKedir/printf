#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments
 * @i: Input
 * @list: List of arguments
 *
 * Return: Width
 */

int get_width(const char *format, int *i, va_list list)
{
	int index;
	int width = 0;

	for (index = *i + 1; format[index] != '\0'; index++)
	{
		if (is_digit(format[index]))
		{
			width *= 10;
			width += format[index] - '0';
		}
		else if (format[index] == '*')
		{
			index++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = index - 1;

	return (width);
}
