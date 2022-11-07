#include "main.h"

/**
 * _printf - Short description.
 * @format: first member.
 *
 * Return: Always 0 (Success)
 */

int _printf(const char *format, ...)
{
	char *tole;
	unsigned int i = 0;
	unsigned int j = 0;

	va_list ap;
	va_start(ap, format);

	while (format && format[j])
		j++;
	while (format && format[i])
	{
		switch(format[i])
		{
			case ('c'):
				*tole = _putchar(va_arg(ap, int));
			break;

			case ('s'):
				*tole = _puts(va_arg(ap, char *));
			break;

			case ('%'):
				*tole = _puts(format);

			case ('d'):
				*tole = _putchar(va_arg(ap, int));
			break;

			case ('i'):
				*tole = _putchar(va_arg(ap, int));
			break;
		}
		i++;
	}
	va_end(ap);
	return (0);
}

