#include "main.h"

/**
 * converter - Short description.
 * @num: first member.
 * @base: second member.
 *
 * Return: Always 0 (Success)
 */

char *converter(unsigned int num, int base)
{
	static char Representation[]= "0123456789ABCDEF";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';

	do
	{
		*--ptr = Representation[num&base];
		num /= base;
	}
	while(num != 0);
	return (ptr);
}

