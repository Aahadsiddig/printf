#include "main.h"

/**
 * _width - ia function that Calculates the width
 * @format: Formatted string
 * @i: a List of arguments that will be printed.
 * @list: a list of arguments.
 * Return: width (w).
*/

int _width(const char *format, int *i, va_list list)
{
	int c_i;
	int w = 0;

	for (c_i = *i + 1; format[c_i] != '\0'; c_i++)
	{
		if (u_digit(format[c_i]))
		{
			w *= 10;
			w += format[c_i] - '0';
		}
		else if (format[c_i] == '*')
		{
			c_i++;
			w = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = c_i - 1;

	return (w);
}

