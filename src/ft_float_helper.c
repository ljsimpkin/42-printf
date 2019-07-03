/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimpkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 11:39:26 by lsimpkin          #+#    #+#             */
/*   Updated: 2019/06/18 11:39:28 by lsimpkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long double	float_handle_mod(va_list list, t_tab *argpart)
{
	long double f;

	if (argpart->lengths == 5 || argpart->lengths == 3)
		f = va_arg(list, long double);
	else
		f = (double)va_arg(list, double);
	return (f);
}

int			float_len(long double nb)
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

long double	rounding(double nb, t_tab *argpart)
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

char		*fractional(long double nb, t_tab *argpart)
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
	frac = (frac < 0) ? frac *= -1 : frac;
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

int			handle_float_sign(double nb, char **convert, t_tab *argpart)
{
	int nve;
	int space;
	int pve;
	int i;

	i = 0;
	nve = ((nb < 0) ? 1 : 0);
	space = (ft_strchr(argpart->flags, ' ')) ? 1 : 0;
	pve = (ft_strchr(argpart->flags, '+') && nb >= 0) ? 1 : 0;
	if (nve)
		*convert = ft_strjoin("-", *convert);
	else if (pve)
		*convert = ft_strjoin("+", *convert);
	else if (space)
		*convert = ft_strjoin(" ", *convert);
	return (ft_strlen(*convert));
}
