#include "main.h"

/**
 * print_int - a function that prints integer
 * @types: a List of arguments of function
 * @buffer: a buffer array
 * @flags: it Calculates active flags of the func
 * @width: gets a width of the function
 * @precision: finds a precision
 * @size: finds Size of the func
 * Return: a number of charactors that will be printed
*/

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	int negative = 0;
	long int z = va_arg(types, long int);
	unsigned long int un;

	z = convert_size_number(z, size);

	if (z == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	un = (unsigned long int)z;

	if (z < 0)
	{
		un = (unsigned long int)((-1) * z);
		negative = 1;
	}

	while (un > 0)
	{
		buffer[x--] = (un % 10) + '0';
		un /= 10;
	}

	x++;

	return (write_number(negative, x, buffer, flags, width, precision, size));
}

