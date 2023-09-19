#include "main.h"

/**
 * _string - a function that prints a string
 * @size: the size for the function
 * @types: a List of arguments
 * @buffer: Buffer array
 * @flags: it Calculates active flags in function
 * @width: width of the function
 * @precision: Precision specification of the function
 * Return: Number of chars printed in the function
*/

int _string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int len = 0, x;
	char *st = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (st == NULL)
	{
		st = "(null)";
		if (precision >= 6)
			st = "      ";
	}

	while (st[len] != '\0')
		len++;
	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &st[0], len);
			for (x = width - len; x > 0; x--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (x = width - len; x > 0; x--)
				write(1, " ", 1);
			write(1, &st[0], len);
			return (width);
		}
	}

	return (write(1, st, len));
}


