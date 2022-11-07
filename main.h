#ifndef _MAIN_H_
#define _MAIM_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(int);
int _puts(const char *str);


char* (*get_function(char *f))(va_list);


/**
 * struct types - struct
 * @id: first member.
 * @fuction: second member.
 */

typedef struct types
{
	char id;
	char* (*f)(va_list);
} print;

#endif
