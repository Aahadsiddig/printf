#include "main.h"

/**
 * _percent - a function that Prints a percent sign
 * @types: a List of arguments of the function
 * @buffer: Buffer array
 * @flags: it  Calculates active flags of the func
 * @width: get width of the func
 * @precision: Precision specification of the func
 * @size: Size specifier of the function
 * Return: Number of charactors printed in the func
*/

int _percent(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

