#include "main.h"

/**
 * _printf - Short description.
 * @format: forst member.
 *
 * Return: always 0 (Success)
 */

int _printf(const char *format, ...)
{
	int state = 0;
	int count = 0;
	int i;
	va_list args;
	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (state == 0)
		{
			if (*format == '%')
				state = 1;
			else
			{
				putchar(*format);
				count += 1;
			}
		}
		else if (state == 1)
		{
			switch (*format)
			{
				case 'c':
				{
					char ch = (char)va_arg(args, int);

					putchar(ch);
					count += 1;
					break;
				}
				case 's':
				{
					char *s = va_arg(args, char *);

					if (s == NULL)
						s = "(null)";
					for (i = 0; s[i]; i++)
					{
					putchar(s[i]);
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

