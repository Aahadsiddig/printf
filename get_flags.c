#include "main.h"

/**
 * _flags - a function that Calculates active flags
 *	in the function
 * @format: Formatted string
 * @i: a parameter that will be taken
 * Return: the Flags
*/

int _flags(const char *format, int *i)
{
	int x, c_i;
	int f = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (c_i = *i + 1; format[c_i] != '\0'; c_i++)
	{
		for (x = 0; FLAGS_CH[x] != '\0'; x++)
			if (format[c_i] == FLAGS_CH[x])
			{
				f |= FLAGS_ARR[x];
				break;
			}

		if (FLAGS_CH[x] == 0)
			break;
	}

	*i = c_i - 1;

	return (f);
}
