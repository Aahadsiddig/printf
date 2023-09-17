#include "main.h"

/**
 * _printf - function selects the correct function to print
 * @format: id to look for
 * Return: the length of the string
 */

int _printf(const char *format, ...)
{
	convert_match m[] = {
		{"%s", printf_string}, {"%c", printf_char},
		{"%%", printf_37}, {"%i", printf_int},
		{"%d", printf_dec}, {"%r", printf_srev},
		{"%R", printf_rot13}, {"%b", printf_bin},
		{"%u", printf_unsigned}, {"%o", printf_oct},
		{"%x", printf_hex}, {"%X", printf_HEX},
		{"%S", printf_exclusive_string}, {"%p", printf_pointer}
	};

	va_list arg;
	int i = 0, j, l = 0;

	va_start(arg, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

here:
	while (format[i] != '\0')
	{
		j = 13;
		while (j >= 0)
		{
			if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
			{
				l += m[j].f(arg);
				i = i + 2;
				goto here;
			}
			j--;
		}
		_putchar(format[i]);
		l++;
		i++;
	}
	va_end(arg);
	return (l);
}


