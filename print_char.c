#include "main.h"

/**
 * _char - a function that Prints a char
 * @size: the size for function
 * @types: a List of arguments
 * @buffer: Buffer array
 * @flags:  it Calculates flags
 * @width: Width of function
 * @precision: Precision specification for function
 * Return: Number of chars printed in function
*/

int _char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
char ch = va_arg(types, int);
return (write_char(ch, buffer, flags, width, precision, size));
}


