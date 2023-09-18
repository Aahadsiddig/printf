#include "main.h"

/**
 * write_unsign - a function that Writes an unsigned number
 * @is_negative: sees if the num is negative
 * @ind: an Index at which the number starts in the buffer of the func
 * @buffer: Array of charactors
 * @flags: gets the Flags
 * @width: gets Width
 * @precision: gets a Precision of the func
 * @size: finds a Size of the function
 * Return: a number of chars that will be written
*/

int write_unsign(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1, x = 0;
	char p = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < len)
		p = ' ';

	while (precision > len)
	{
		buffer[--ind] = '0';
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		p = '0';

	if (width > len)
	{
		for (x = 0; x < width - len; x++)
			buffer[x] = p;

		buffer[x] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], len) + write(1, &buffer[0], x));
		}
		else
		{
			return (write(1, &buffer[0], x) + write(1, &buffer[ind], len));
		}
	}

	return (write(1, &buffer[ind], len));
}
