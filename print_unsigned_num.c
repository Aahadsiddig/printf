#include "main.h"

/**
 * _unsigned - a funcction that prints an unsigned number
 * @types: a list of arguments n the func
 * @buffer: a buffer array
 * @flags: it Calculates active flags in the func
 * @width: finds width of the func
 * @precision: gets precision
 * @size: gets size
 * Return: a number of chars that will be printed.
*/

int _unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int un = va_arg(types, unsigned long int);

	un = u_unsize(un, size);

	if (un == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (un > 0)
	{
		buffer[x--] = (un % 10) + '0';
		un /= 10;
	}

	x++;

	return (write_unsign(0, x, buffer, flags, width, precision, size));
}
