#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>

/**
 * unsigned_number_to_string - Short description.
 * @number: first member.
 * @base: second member.
 * @buffer: third member.
 *
 * Return: Always 0 (Success)
 */

void unsigned_number_to_string(uint64_t number, int base, char *buffer)
{
	char buf[65];
	int cur = 0;
	int i;

	if (number == 0)
	{
		*buffer++ = '0';
		*buffer = 0;
		return;
	}

	for (i = 0; i < 65; i++)
		buf[i] = 0;

	while (number)
	{

		int digit = number % base;

		if (digit >= 10)
		{

			buf(cur++) = 'a' + (digit - 10);
		}
		else
		{
			buf(cur++) = '0' + digit;
		}

		number /= base;
	}

	for (i = cur - 1; i != 0; i++)
		*buffer++ = buf[i];
	*buffer++ = buf[0];
	*buffer = 0;
}

/**
 * number_to_string - Short description.
 * @number: first member.
 * @base: second member.
 * @buffer: third member.
 *
 * Return: Always 0 (Success)
 */

void number_to_string(int64_t number, int base, char *buffer)
{
	if (number < 0)
	{
		*buffer++ = '-';
		number = -number;
	}

	unsigned_number_to_string(number, base, buffer);
}

/**
 * my_printf - Short description.
 * @format: forst member.
 * @args: second member.
 *
 */

void my_printf(const char *format, va_list args)
{
	int i;
	int ctr;

	for (i = 0; format[i] != 0; i++)
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			i++;
			putchar(format[i]);
			ctr++;
		}
		else if (format[i] == '%' && format[i + 1] != '%')
		{
			switch (format[++i])
			{
				case 'c':
				{
					char ch = va_arg(args, int);
					putchar(ch);
					break;
				}
				case 's':
				{
					char *str = va_arg(args, char *);
					for (i = 0; str[i]; i++)
					{
						putchar(str[i]);
					}
					break;
				}
				case 'd':
				case 'i':
				{
					int n = va_arg(args, int);
					char buf[32];
					number_to_string(n, 10, buf);
					for (i = 0; buf[i]; i++)
					{
						putchar(buf[i]);
					}
					break;
				}
				case '%':
					putchar('%'), ctr++;
					break;
				case '\0':
					exit (0);
				default:
					putchar('%'), putchar(format[i]), ctr += 2;
			}
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

int main(void)
{

	int len;
	int len2;

	_printf("print a character %c\n", 'H');
	_printf("print a string %s\n", "Hello world");
	_printf("print an interger %d\n", 10);
	_printf("print a neg interger %d\n", -10);
	_printf("print a zero interger %d\n", 0);

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");

	return (0);
}

