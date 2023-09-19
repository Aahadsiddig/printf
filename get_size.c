#include "main.h"

/**
 * _size - a function that Calculates the size of argument
 * @format: a Formatted string
 * @i: a List of arguments that will be printed.
 * Return: size (s).
*/

int _size(const char *format, int *i)
{
	int c_i = *i + 1;
	int s = 0;
	if (format[c_i] == 'l')
		s = S_LONG;
	else if (format[c_i] == 'h')
		s = S_SHORT;
	if (s == 0)
		*i = c_i - 1;
	else
		*i = c_i;
	return (s);
}
