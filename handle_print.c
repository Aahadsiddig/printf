#include "main.h"

/**
 * handle_print - a function that prints an argument
 *	based on its type
 * @fmt: a Formatted string
 * @list: a List of arguments that will be printed.
 * @ind: integer
 * @buffer: Buffer array
 * @flags: it Calculates active flags of the function
 * @width: finds width.
 * @precision: gets Precision
 * @size: gets Siz
 * Return: 1 or 2;
*/

int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int x, unknownL = 0, printedC = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (x = 0; fmt_types[x].fmt != '\0'; x++)
		if (fmt[*ind] == fmt_types[x].fmt)
			return (fmt_types[x].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[x].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknownL += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknownL += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknownL += write(1, &fmt[*ind], 1);
		return (unknownL);
	}
	return (printedC);
}

