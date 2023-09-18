#include "main.h"

/**
 * write_num_buffer - a function that writes a number using a bufffer
 * @ind: Index for the  number starts on the buffer
 * @buffer: gets Buffer of func
 * @flags: gets flags of func
 * @width: gets width of func
 * @prec: finds precision specifier of func
 * @length: gets length of func
 * @padd: Pading char of func
 * @extra_c: Extra char in the function
 * Return: Number of printed char
*/

int write_num_buffer(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int x, p_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (x = 1; x < width - length + 1; x++)
			buffer[x] = padd;
		buffer[x] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], x - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], x - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--p_start] = extra_c;
			return (write(1, &buffer[p_start], x - p_start) +
				write(1, &buffer[ind], length - (1 - p_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}
