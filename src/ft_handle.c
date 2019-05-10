#include "ft_printf.h"

int	handle_s(va_list list, cv_table *argpart)
{
	int		len;
	char	*str;

	len = 0;
	str = va_arg(list, char *);
	len = dup_put_char(ft_strlen(str), argpart->width, ' ') + ft_strlen(str);
	ft_putstr(str);
	write(1, str, ft_strlen(str));
	return (len);
}

int	handle_c(va_list list, cv_table *argpart)
{
	int		len;
	char	ch;

	len = 0;
	ch = va_arg(list, int);
	if (ft_strchr(argpart->flags, '-'))
	{
		ft_putchar(ch);
		len = dup_put_char(1, argpart->width, ' ') + 1;
	}
	else
	{
		len = dup_put_char(1, argpart->width, ' ') + 1;
		ft_putchar(ch);
	}
	return (len);
}

int	handle_d(va_list list, cv_table *argpart)
{
	int			len;
	long long	nb;
	char		*convert;
	char		*padding;

	len = 0;
	nb = handle_length(list, argpart);
	convert = ft_strnew(ft_number_len2(nb));
	convert = ft_strcpy(convert, ft_itoa2(positive2(nb)));
	padding = ft_handle_width(nb, convert, argpart);
	handle_zeroes(padding, &convert, argpart);
	handle_sign(nb, &convert, argpart);

	if (ft_strchr(argpart->flags, '-'))
		convert = ft_strjoin(convert, padding);
	else
		convert = ft_strjoin(padding, convert);
	len = ft_strlen(convert);
	write(1, convert, len);

	return (len);
}

void	handle_hash(char **convert, cv_table *argpart)
{
	if (argpart->specifier == 'o' && ft_strchr(argpart->flags, '#'))
		*convert = ft_strjoin("0", *convert);
	else if ((argpart->specifier == 'x' || argpart->specifier == 'X') &&
		ft_strchr(argpart->flags, '#'))
		*convert = ft_strjoin("0x", *convert);
	else if (argpart->specifier == 'p')
		*convert = ft_strjoin("0x", *convert);
}

int		handle_o(va_list list, cv_table *argpart)
{
	int				len;
	char			*padding;
	unsigned int	nb;
	char			*convert;

	len = 0;
	nb = va_arg(list, int);
	convert = ft_strnew(ft_digilen(nb));
	convert = ft_strcpy(convert, ft_itoa_base(nb, 8));
	handle_hash(&convert, argpart);

	padding = ft_handle_width(nb, convert, argpart);
	handle_zeroes(padding, &convert, argpart);

	if (ft_strchr(argpart->flags, '-'))
		convert = ft_strjoin(convert, padding);
	else
		convert = ft_strjoin(padding, convert);

	len = ft_strlen(convert);
	write(1, convert, len);
	return (len);
}

int		handle_u(va_list list, cv_table *argpart)
{
	int				len;
	char			*padding;
	unsigned int	nb;
	char			*convert;

	len = 0;
	nb = va_arg(list, int);
	convert = ft_strnew(ft_digilen(nb));
	convert = ft_strcpy(convert, ft_itoa_base(nb, 10));
	handle_hash(&convert, argpart);

	padding = ft_handle_width(nb, convert, argpart);
	handle_zeroes(padding, &convert, argpart);

	if (ft_strchr(argpart->flags, '-'))
		convert = ft_strjoin(convert, padding);
	else
		convert = ft_strjoin(padding, convert);

	len = ft_strlen(convert);
	write(1, convert, len);
	return (len);
}

int		handle_x(va_list list, cv_table *argpart)
{
	int				len;
	char			*padding;
	unsigned int	nb;
	char			*convert;

	len = 0;
	nb = va_arg(list, int);
	convert = ft_strnew(ft_digilen(nb));
	convert = ft_strcpy(convert, ft_itoa_base2(nb, 16, 0));
	handle_hash(&convert, argpart);

	padding = ft_handle_width(nb, convert, argpart);
	handle_zeroes(padding, &convert, argpart);

	if (ft_strchr(argpart->flags, '-'))
		convert = ft_strjoin(convert, padding);
	else
		convert = ft_strjoin(padding, convert);

	len = ft_strlen(convert);
	write(1, convert, len);
	return (len);
}

int		handle_X(va_list list, cv_table *argpart)
{
	int				len;
	char			*padding;
	unsigned int	nb;
	char			*convert;

	len = 0;
	nb = va_arg(list, int);
	convert = ft_strnew(ft_digilen(nb));
	convert = ft_strcpy(convert, ft_itoa_base2(nb, 16, 1));
	handle_hash(&convert, argpart);

	padding = ft_handle_width(nb, convert, argpart);
	handle_zeroes(padding, &convert, argpart);

	if (ft_strchr(argpart->flags, '-'))
		convert = ft_strjoin(convert, padding);
	else
		convert = ft_strjoin(padding, convert);

	len = ft_strlen(convert);
	write(1, convert, len);
	return (len);
}

int		handle_p(va_list list, cv_table *argpart)
{
	unsigned long long	nb;
	int					len;
	char				*convert;
	char				*padding;

	convert = ft_strnew(ft_digilen(nb));
	padding = ft_handle_width(nb, convert, argpart);
	nb = (unsigned long long)va_arg(list, void *);
	len = 0;
	convert = ft_strcpy(convert, ft_itoa_fd_base2(nb, 1, 16, 0));

	handle_zeroes(padding, &convert, argpart);
	handle_hash(&convert, argpart);

	if (ft_strchr(argpart->flags, '-'))
		convert = ft_strjoin(convert, padding);
	else
		convert = ft_strjoin(padding, convert);

	len = ft_strlen(convert);
	write(1, convert, len);
	return (len);
	return (1);
}

long double	float_handle_mod(va_list list, cv_table *argpart)
{
	long double f;

	if (argpart->lengths == 5 || argpart->lengths == 3)
		f = va_arg(list, long double);
	else
		f = (double)va_arg(list, double);
	return (f);
}

int	float_len(long double nb)
{
	int tmp;
	int count;

	tmp = 0;
	count = 0;
	while (nb > 1)
		nb /= 10;

	while (nb)
	{
		nb *= 10;
		nb = nb - (int)nb;
		count++;
	}
	return (count);
}

long double	rounding(double nb, cv_table *argpart)
{
	int		i;
	double	rd;
	int		precision;
	int		sign;

	sign = (nb < 0) ? 1 : 0;

	i = 0;
	precision = argpart->precision ? argpart->precision : 6;

	if (ft_strchr(argpart->conversions, '.') &&
		precision == 6 && argpart->precision == 0)
		precision = 0;

	rd = 5;

	while (i <= precision)
	{
		rd /= 10;
		i++;
	}

	nb = sign ? nb - rd : nb + rd;

	return (nb);
}

char	*fractional(long double nb, cv_table *argpart)
{
	int			i;
	int			fracint;
	int			precision;
	long double	frac;
	char		*str;

	frac = nb - (int)nb;
	i = 0;
	fracint = 0;
	precision = (argpart->precision ||
		ft_strchr(argpart->conversions, '.')) ? argpart->precision : 6;
	if (frac < 0)
		frac *= -1;
	str = malloc(sizeof(char) * precision + 3);
	if (precision)
		str[i] = '.';
	while (i < precision + 1)
	{
		i++;
		frac *= 10;
		fracint = (int)(frac);
		str[i] = (fracint + '0');
		frac = frac - fracint;
	}
	str[i] = '\0';
	return (str);
}

int	handle_f(va_list list, cv_table *argpart)
{
	double	nb;
	char	*integ;
	char	*frac;
	char	*convert;
	char	*padding;
	int		len;

	nb = float_handle_mod(list, argpart);
	nb = rounding(nb, argpart);

	integ = ft_itoa(positive((int)nb));
	frac = fractional(nb, argpart);
	convert = ft_strjoin(integ, frac);
	padding = ft_handle_width(nb, convert, argpart);
	handle_zeroes2(padding, &convert, argpart);
	handle_sign(nb, &convert, argpart);

	if (ft_strchr(argpart->flags, '-'))
		convert = ft_strjoin(convert, padding);
	else
		convert = ft_strjoin(padding, convert);

	len = ft_strlen(convert);
	write(1, convert, len);
	return (1);
}

int		handle_percent(va_list list, cv_table *argpart)
{
	int		len;
	char	*convert;
	char	*padding;

	convert = ft_strdup("%");
	padding = ft_handle_width(1, convert, argpart);
	len = 0;
	handle_zeroes(padding, &convert, argpart);

	if (ft_strchr(argpart->flags, '-'))
		convert = ft_strjoin(convert, padding);
	else
		convert = ft_strjoin(padding, convert);
	len = ft_strlen(convert);
	write(1, convert, len);
	return (1);
}