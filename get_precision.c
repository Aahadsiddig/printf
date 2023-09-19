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
	int ci = *i + 1;
	int pr = -1;

	if (format[ci] != '.')
	{
		return (pr);
	}

	pr = 0;

	for (ci += 1; format[ci] != '\0'; ci++)
	{
		if (u_digit(format[ci]))
		{
			pr *= 10;
			pr += format[ci] - '0';
		}
		else if (format[ci] == '*')
		{
			ci++;
			pr = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = ci - 1;

	return (pr);
}

