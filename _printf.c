#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * my_printf - Short description.
 * @format: forst member.
 * @args: second member.
 *
 */

void my_printf(const char *format, va_list args)
{
	int state = 0;

	while (*format)
	{
		if (state == 0)
		{
			if (*format == '%')
				state = 1;
			else
				putchar(*format);
		}
		else if (state == 1)
		{
			switch (*format)
			{
				case 'c':

				{
					char ch = va_arg(args, int);

					putchar(ch);
					break;
				}
				case 's':
				{
					const char *s = va_arg(args, const char *);

					while (*s)
					{
						putchar(*s++);
					}
					break;
				}
			}
			state = 0;
		}
		format++;
	}
}

/**
 * _printf - Short description.
 * @format: first member.
 *
 * Return: Always 0 (Success)
 */

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	my_printf(format, args);

	va_end(args);
	return (0);
}

