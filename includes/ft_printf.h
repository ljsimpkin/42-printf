/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimpkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:06:30 by lsimpkin          #+#    #+#             */
/*   Updated: 2019/06/19 11:06:32 by lsimpkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# define SPECI "csdiouxXpf%"
# define FLAGS "#0-+ "
# define MAX(x,y) x > y ? x : y

# define HH	1
# define H	2
# define L	3
# define LL	4

static const char	g_base[17] = "0123456789ABCDEF";
static const char	g_lowr[17] = "0123456789abcdef";

int						ft_printf(const char *format, ...);

typedef struct			s_table
{
	char	*conversions;
	char	specifier;
	char	*flags;
	int		lengths;
	int		zero_flag;
	int		error;
	int		formatlen;
	size_t	width;
	size_t	precision;
	int		len;

}						t_tab;

int						parse(t_tab *argpart, const char *format);
char					*ft_search(const char *str, char*search);

int						handle_c(va_list list, t_tab *argpart);
int						handle_s(va_list list, t_tab *argpart);
int						handle_d(va_list list, t_tab *argpart);
int						handle_o(va_list list, t_tab *argpart);
int						handle_u(va_list list, t_tab *argpart);
int						handle_x(va_list list, t_tab *argpart);
int						handle_cap_x(va_list list, t_tab *argpart);
int						handle_p(va_list list, t_tab *argpart);
int						handle_f(va_list list, t_tab *argpart);
int						handle_percent(va_list list, t_tab *argpart);

char					*handle_zero(char *padding, t_tab *argpart);
void					handle_zeroes(char
*padding, char **convert, t_tab *argpart);
char					*handle_zero2(char *padding, t_tab *argpart);
void					handle_zeroes2(char
*padding, char **convert, t_tab *argpart);
int						handle_sign(long long
nb, char **convert, t_tab *argpart);
void					handle_hash(char **convert, t_tab *argpart);
void					handle_hash2(char
**convert, t_tab *argpart, unsigned long long int nb);

long long int			handle_length(va_list list, t_tab *argpart);
unsigned long long int	unsigned_handle_length(va_list list, t_tab *argpart);

long double				float_handle_mod(va_list list, t_tab *argpart);
int						float_len(long double nb);
long double				rounding(double nb, t_tab *argpart);
char					*fractional(long double nb, t_tab *argpart);
int						handle_precision(char **convert, t_tab *argpart);
char					*handle_strprecision(char *str, t_tab *argpart);
char					*handle_strwidth(char *mod, t_tab *argpart);

char					*ft_handle_width(long long
nb, char *convert, t_tab *argpart);
int						call_handler(va_list list, t_tab *argpart);
int						dup_put_char(int len, int width, int ch);

int						handle_float_sign(double nb, char
**convert, t_tab *argpart);
int						ft_sign(long long d, t_tab *argpart);
long long				positive(long long nb);

int						ft_atoi_skip(const char *s);
char					*ft_itoa_base(long long value, int base, int uppercase);
char					*ft_strdupchr(int len, char c);
void					handle_hash(char **convert, t_tab *argpart);
char					*handle_nbprecision(char *str, t_tab *argpart);
char					*handle_pprecision(char *convert, t_tab *argpart);
char					*handle_strzeroes(char *convert, t_tab *argpart);
char					*ft_uns_itoa_base(unsigned long long
value, int base, int uppercase);
#endif
