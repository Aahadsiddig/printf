#include "main.h"

/**
 * print_pointer - a function that Prints the value of a pointer variable
 * @types: a List of arguments of the function
 * @buffer: Buffer array
 * @flags: it Calculates active flags of the function
 * @width: get width of the function
 * @precision: a Precision specification of the function
 * @size: a Size specifier of the function
 * Return: Number of chars printed in the function
*/

int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = 0, p = ' ';
	int i = BUFF_SIZE - 2, len = 2, p_start = 1;
	unsigned long num_add;
	char ch[] = "0123456789abcdef";
	void *add = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (add == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_add = (unsigned long)add;

	while (num_add > 0)
	{
		buffer[i--] = ch[num_add % 16];
		num_add /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		p = '0';
	if (flags & F_PLUS)
		c = '+', len++;
	else if (flags & F_SPACE)
		c = ' ', len++;

	i++;

	return (write_pointer(buffer, i, len,
				width, flags, p, c, p_start));
}
