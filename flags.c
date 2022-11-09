#include "main.h"

/**
 * printflags - Function that contains the printf flags.
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
		{'\0', NULL}
	};
	int j;

		for (j = 0; j < 6; j++)
		{
			if (format == func[j].c)
			{
				return (func[j].f);
			}
		}
	return (0);
}

