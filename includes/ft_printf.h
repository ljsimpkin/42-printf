#ifndef PRINTF_H
#define PRINTF_H

#include "libft.h"
#include <stdarg.h> // man 3 stdarg
#define SPECI "csdiouxXpf%"
#define FLAGS "#0-+ "
#define MAX(x,y) x > y ? x : y

#define HH 1
#define H 2
#define L 3
#define LL 4


int ft_printf(const char *format, ...);

typedef struct s_table
{
	char *conversions;
	char specifier;
	char *flags;
	int lengths;
	int zero_flag;
	int error;
	int formatlen;
	size_t width;
	size_t precision;
	int len;

}                cv_table;

int parse(cv_table *argpart, const char *format);
int search_specifiers(const char *format);
int search_flags(const char *format);
int search_length(const char *format);

int handle_c(va_list list, cv_table *argpart);
int handle_s(va_list list, cv_table *argpart);
int handle_d(va_list list, cv_table *argpart);
int handle_o(va_list list, cv_table *argpart);
int handle_u(va_list list, cv_table *argpart);
int handle_x(va_list list, cv_table *argpart);
int handle_X(va_list list, cv_table *argpart);
int handle_p(va_list list, cv_table *argpart);
int handle_f(va_list list, cv_table *argpart);
int handle_percent(va_list list, cv_table *argpart);

long double	float_handle_mod(va_list list, cv_table *argpart);
int float_len(long double nb);
long double rounding(double nb, cv_table *argpart);
char *fractional(long double nb, cv_table *argpart);

void handle_hash(char **convert, cv_table *argpart);

int search_width(const char *format);
int search_precision(const char *format);
char *ft_search(const char *str, char*search);
int call_handler(va_list list, cv_table *argpart);
int	ft_atoi_skip(const char *s);
void ft_putnbr_fd_base(unsigned long long n, int fd, int base, int upper);
int dup_put_char(int len, int width, int ch);

int ft_digilen(long long nb);
int dup_put_char2(int len, int ch);

void handle_zeroes(char *padding, char **convert, cv_table *argpart);
int handle_precision(char **convert, cv_table *argpart);
char *ft_handle_width(long long nb, char * convert, cv_table *argpart);
char *ft_strnewchr(int len, char c);
int ft_sign(long long d, cv_table *argpart);
int remove_dupsign(char *convert);
char * handle_zero(char *padding, cv_table *argpart);
long long positive(long long nb);
int handle_sign(long long nb, char **convert, cv_table *argpart);

char	*ft_itoa_base(int n, int base);
char	*ft_itoa_base2(int n, int base, int uppercase);
char	*itoa_base3(int value, int base);

char		*ft_itoa2(long long n);
int	ft_number_len2(long long nb);
char*	ft_itoa_fd_base2(unsigned long long n, int fd, int base, int upper);
double positive2(double nb);
char		*ft_ptoa(void *p, char c);
char * handle_zero2(char *padding, cv_table *argpart);
void handle_zeroes2(char *padding, char **convert, cv_table *argpart);
long long int handle_length(va_list list, cv_table *argpart);
#endif
