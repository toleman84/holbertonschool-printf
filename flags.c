#include "main.h"

/**
 * printflags - Function that recieves the arguments of _printf
 * and return the corresponding function.
 * @format: String that printflags takes.
 *
 * Return: Always 0 (Success)
 */

int (*printflags(const char format))(va_list)
{
	perc func[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_perc},
		{'d', val_n},
		{'i', val_n},
		{'\0', NULL}
	};
	int j;

	if (format)
	{
		for (j = 0; j < 7; j++)
		{
			if (format == func[j].c)
			{
				return (func[j].f);
			}
		}
		_putchar('%');
		_putchar(format);
		return (border_case);
	}
	else
		return (NULL);
	return (0);
}

/**
 * border_case - Function that return 2.
 * @ap: The arguments.
 *
 * Return: 2
 */

int border_case(__attribute__((unused))va_list ap)
{
	return (2);
}

