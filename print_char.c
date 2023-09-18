#include "main.h"

/**
 * print_char - a function that Prints a char
 * @types: a List of arguments
 * @buffer: Buffer array
 * @flags:  it Calculates flags
 * @width: Width of function
 * @precision: Precision specification for function
 * @size: Size specifier for function
 * Return: Number of chars printed in function
*/

int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char ch = va_arg(types, int);

	return (handle_write_char(ch, buffer, flags, width, precision, size));
}


