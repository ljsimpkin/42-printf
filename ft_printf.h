#ifndef PRINTF_H
#define PRINTF_H

#include "libft/libft.h"
#include <stdarg.h> // man 3 stdarg
#define SPECI "csdiouxXp"
#define FLAGS "#0-+ "

int ft_printf(const char *format, ...);

typedef struct s_table
{
	char *conversions;
	char specifier;
	char *flags;
	int error;
	int conlen;
	size_t width;
	size_t precision;
}                conversion_table;

int search_specifiers(const char *format);
int search_flags(const char *format);
int search_length(const char *format);
int parse(conversion_table *argpart, const char *format);

/*
min number of chars to be printed. If the value to be printed is
shorter than this number, the reult is padded with blank spaces
*/
int search_width(const char *format);
int search_precision(const char *format);
char *ft_search(const char *str, char*search);
int call_handler(va_list list, conversion_table *argpart);
int	ft_atoi_skip(const char *s);
void ft_putnbr_fd_base(unsigned long long n, int fd, int base, int upper);
int dup_put_char(int len, int width, int ch);
int handle_c(va_list list, conversion_table *argpart);
int ft_digilen(int nb);
int dup_put_char2(int len, int ch);

#endif
