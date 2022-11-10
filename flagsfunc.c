#include "main.h"

int print_int(int n);
int val_n(va_list ap);

/**
 * print_str - Function that print a string.
 * @ap: The arguments.
 *
 * Return: Always 0 (Success)
 */

int print_str(va_list ap)
{
	char *str = va_arg(ap, char *);
	int i;

	if (str)
	{
		for (i = 0; *str; i++)
		{
			_putchar(*str);
			str = str + 1;
		}
	}
	else
	{
		return (write(1, "(null)", 6));
	}
	return (i);
}

/**
 * print_perc - Function that print a percentage.
 * @ap: The arguments.
 *
 * Return: Always 0 (Success)
 */

int print_perc(__attribute__((unused))va_list ap)
{

	return (_putchar('%'));
}

/**
 * print_char - Function that prints a single character.
 * @ap: The arguments.
 *
 * Return: Always 0 (Success)
 */

int print_char(va_list ap)
{
	int c = va_arg(ap, int);

	return (write(1, &c, 1));
}

/**
 * print_int - Function that print a interger
 * @ap: The arguments
 *
 * Return: Always 0 (Success)
 */

int print_int(int n)
{

	if (n < 0)
	{
		_putchar('-');
		n = n -1;
	}
	if (n > 9) print_int(n / 10);
	{
		_putchar('0' + (n % 10));
	}
	return (0);
}

/**
 * val_n - Short description.
 * @ap: The arguments
 *
 * Return: Always 0 (Success)
 */

int val_n(va_list ap)
{
	int n = va_arg(ap, int);

	return (print_int(n));
}

