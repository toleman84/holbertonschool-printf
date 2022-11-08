#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * my_printf - Short description.
 * @format: forst member.
 * @args: second member.
 *
 */

int _printf(const char *format, ...)
{
	int state = 0;
	int count = 0;
	va_list args;
	va_start(args, format);
	while (*format)
	{
		if (state == 0)
		{
			if (*format == '%')
			{
				state = 1;
			}
			else
			{
				putchar(*format);
				count += 1;
			}
		}
		else if (state == 1)
		{
			switch (*++format)
			{
				case 'c':
				{
					char ch = va_arg(args, int);
				
					putchar(ch);
					count += 1;
					break;
				}
				case 's':
				{
					const char *s = va_arg(args, const char *);

					while (*s)
					{
						putchar(*s++);
						count += 1;
					}
					break;
				}
				case '%':
					
					putchar('%');
					count += 1;
					break;
				case '\0':
					exit(0);
			}
			state = 0;
		}
		format++;
	}
	va_end(args);
	return (count);
}
