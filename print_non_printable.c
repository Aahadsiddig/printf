#include "main.h"

/**
 * _non_printable - a function that Prints ascii codes
 *	of non printable chars in hexa
 * @types: a List of arguments of func
 * @buffer: Buffer array
 * @flags: it Calculates active flags of the function
 * @width: get width of the function
 * @precision: a Precision specification for the function
 * @size: a Size specifier of the function
 * Return: Number of charactors printed in the func
*/

int _non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int x = 0, y = 0;
	char *st = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (st == NULL)
		return (write(1, "(null)", 6));

	while (st[x] != '\0')
	{
		if (u_printable(st[x]))
			buffer[x + y] = st[x];
		else
			y += u_hexa_code(st[x], buffer, x + y);

		x++;
	}

	buffer[x + y] = '\0';

	return (write(1, buffer, x + y));
}

