#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: Take a parameter
 *
 * Return: Flags
 */

int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, current_index;
	int flags = 0;
	const char FLAGS_CHARACTERS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current_index = *i + 1; format[current_index] != '\0'; current_index++)
	{
		for (j = 0; FLAGS_CHARACTERS[j] != '\0'; j++)
			if (format[current_index] == FLAGS_CHARACTERS[j])
			{
				flags |= FLAGS_ARRAY[j];
				break;
			}

		if (FLAGS_CHARACTERS[j] == 0)
			break;
	}

	*i = current_index - 1;

	return (flags);
}
