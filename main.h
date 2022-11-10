#ifndef PRINTF
#define PRINTF

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int _printf(const char *format, ...);
int _putchar(char c);

int (*printflags(const char format))(va_list);

int print_str(va_list ap);
int print_perc(va_list ap);
int print_char(va_list ap);

int border_case(__attribute__((unused))va_list ap);


/**
 * struct percentage - Short description.
 * @c: first member.
 * @f: second member.
 */

typedef struct percentage
{
	char c;
	int (*f)(va_list ap);
} perc;

#endif
