#include "main.h"

/**
 * print_binary - a finction that prints an unsigned number
 * @types: a list of arguments in the function
 * @buffer: a buffer array
 * @flags: it Calculates active flags in the func
 * @width: finds width of the function
 * @precision: finds precision
 * @size: finds size
 * Return: a numbers of charactors that will be printed.
*/

int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int x, y, j, add;
	unsigned int z[32];
	int counter;
	char c;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	x = va_arg(types, unsigned int);
	y = 2147483648;
	z[0] = x / y;
	for (j = 1; j < 32; j++)
	{
		y /= 2;
		z[j] = (x / y) % 2;
	}
	for (j = 0, add = 0, counter = 0; j < 32; j++)
	{
		add += z[j];
		if (add || j == 31)
		{
			c = '0' + z[j];

			write(1, &c, 1);
			counter++;
		}
	}
	return (counter);
}

