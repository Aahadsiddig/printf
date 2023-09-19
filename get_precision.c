#include "main.h"

/**
 * _precision - a function that Calculates the precision
 * @format: Formatted string in which to print
 * @i: a List of arguments that will be printed
 * @list: a list of arguments
 * Return: Precision.
*/

int _precision(const char *format, int *i, va_list list)
{
	int curr_i = *i;
	int precision = 0;

	if (format[curr_i] != '.')
	{

		return (precision);
	}

	curr_i++;

	if (format[curr_i] == '*')
	{
		va_arg(list, int);
		curr_i++;
	}
	else
	{
		while (u_digit(format[curr_i]))
		{
			precision = precision * 10 + (format[curr_i] - '0');
			curr_i++;
		}
	}
	*i = curr_i;

	return (precision);
}

