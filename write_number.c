#include "main.h"

/**
 * write_number - a function that Prints a string
 * @is_negative: a List of arguments in the function
 * @ind: char
 * @buffer: a Buffer array
 * @flags: it Calculates active flags of the function
 * @width: finds width of the func
 * @precision: finds a precision of the func
 * @size: finds Size of the function
 * Return: a number of chars that will be printed.
*/

int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1;
	char p = ' ', ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		p = '0';
	if (is_negative)
		ch = '-';
	else if (flags & F_PLUS)
		ch = '+';
	else if (flags & F_SPACE)
		ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		len, p, ch));
}
