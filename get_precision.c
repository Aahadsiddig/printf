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
	int c_i = *i + 1;
	int pr = -1;

	if (format[c_i] != '.')
		return (pr);

	c_i++;
	pr = 0;

	while (format[c_i] != '\0')
	{
	if (u_digit(format[c_i]))
	{
		pr *= 10;
		pr += format[c_i] - '0';
		}
		else if (format[c_i] == '*')
		{
			c_i++;
			pr = va_arg(list, int);
			break;
		}
		else
			break;
	}
	c_i++;
	*i = c_i - 1;

	return (pr);
}

