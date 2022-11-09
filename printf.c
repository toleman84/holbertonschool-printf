#include "main.h"

/**
 * _printf - Function that mimics the function defined by stdio.h printf.
 * @format: The arguments passed to the function.
 *
 * Return: Success
 */

int _printf(const char *format, ...)
{
	int (*f)(va_list ap);
	va_list ap;
	int i;
	int count = 0;

	va_start(ap, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			f = printflags(format[i]);
			if (f)
			{
				count += f(ap);
			}
		}
		else
		{
			count += _putchar(format[i]);
		}
	}
	va_end(ap);
	return (count);

}

