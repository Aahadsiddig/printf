#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - function that do the printf
 * @format: a formatted for the function
 * Return: a printed charactors in the func
*/

int _printf(const char *format, ...)
{
	int x, p = 0, pch = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];
if (format == NULL)
return (-1);
	va_start(list, format);
	for (x = 0; format && format[x] != '\0'; x++)
	{
		if (format[x] != '%')
		{
			buffer[buff_ind++] = format[x];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			pch++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = _flags(format, &x);
			width = _width(format, &x, list);
			precision = _precision(format, &x, list);
			size = _size(format, &x);
			++x;
			p = print(format, &x, list, buffer,
				flags, width, precision, size);
			if (p == -1)
				return (-1);
			pch += p;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (pch);
}

/**
 * print_buffer - a function that prints the contents of the buffer
 * @buffer: An rray of charactors in the func
 * @buff_ind: an index to add next char, represents the length of the function
*/

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
