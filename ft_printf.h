#ifndef PRINTF_H
#define PRINTF_H

#include "libft/libft.h"
#include <stdarg.h> // man 3 stdarg
#define SPECI "scd"

void ft_printf(const char *format, ...);

typedef struct s_table
{
	char *conversions;
	char specifier;
	char *flag;
	int error;
}                conversion_table;

int search_specifiers(const char *format);
int search_flags(const char *format);
int search_length(const char *format);

/*
min number of chars to be printed. If the value to be printed is
shorter than this number, the reult is padded with blank spaces
*/
int search_width(const char *format);
int search_precision(const char *format);
char *ft_search(const char *str, char*search);


#endif
