#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

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
	int state = 0;
	int i;
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

int main(void)
{
	_printf("print a character %c\n", 'H');
	_printf("print a string %s\n", "Hello world");
	_printf("print an interger %d\n", 10);
	_printf("print a neg interger %d\n", -10);
	_printf("print a zero interger %d\n", 0);

	return (0);
}

