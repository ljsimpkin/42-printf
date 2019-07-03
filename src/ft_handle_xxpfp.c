/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_xxpfp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimpkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 10:36:46 by lsimpkin          #+#    #+#             */
/*   Updated: 2019/06/19 10:36:47 by lsimpkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_x(va_list list, t_tab *argpart)
{
	int					len;
	unsigned long long	nb;
	char				*convert;

	len = 0;
	nb = unsigned_handle_length(list, argpart);
	convert = ft_strnew(ft_number_len(nb));
	convert = ft_strcpy(convert, ft_uns_itoa_base(nb, 16, 0));
	convert = handle_pprecision(convert, argpart);
	convert = handle_strzeroes(convert, argpart);
	handle_hash(&convert, argpart);
	convert = handle_strwidth(convert, argpart);
	len = ft_strlen(convert);
	write(1, convert, len);
	return (len);
}

int		handle_cap_x(va_list list, t_tab *argpart)
{
	int					len;
	unsigned long long	nb;
	char				*convert;

	len = 0;
	nb = unsigned_handle_length(list, argpart);
	convert = ft_strnew(ft_number_len(nb));
	convert = ft_strcpy(convert, ft_uns_itoa_base(nb, 16, 1));
	convert = handle_pprecision(convert, argpart);
	convert = handle_strzeroes(convert, argpart);
	handle_hash(&convert, argpart);
	convert = handle_strwidth(convert, argpart);
	len = ft_strlen(convert);
	write(1, convert, len);
	return (len);
}

int		handle_p(va_list list, t_tab *argpart)
{
	int						len;
	unsigned long long int	nb;
	char					*convert;

	len = 0;
	nb = (unsigned long long)va_arg(list, void *);
	convert = ft_strdup(ft_itoa_base(nb, 16, 0));
	convert = handle_pprecision(convert, argpart);
	handle_hash(&convert, argpart);
	convert = handle_strwidth(convert, argpart);
	len = ft_strlen(convert);
	write(1, convert, len);
	free(convert);
	return (len);
}

int		handle_f(va_list list, t_tab *argpart)
{
	double	nb;
	char	*integ;
	char	*frac;
	char	*convert;
	char	*padding;

	nb = float_handle_mod(list, argpart);
	nb = rounding(nb, argpart);
	integ = ft_itoa(positive((int)nb));
	frac = fractional(nb, argpart);
	convert = ft_strjoin(integ, frac);
	padding = ft_handle_width(nb, convert, argpart);
	handle_zeroes2(padding, &convert, argpart);
	handle_float_sign(nb, &convert, argpart);
	if (ft_strchr(argpart->flags, '-'))
		convert = ft_strjoin(convert, padding);
	else
		convert = ft_strjoin(padding, convert);
	write(1, convert, ft_strlen(convert));
	return (ft_strlen(convert));
}

int		handle_percent(va_list list, t_tab *argpart)
{
	int		len;
	char	*convert;
	char	*padding;
	int		lst;

	if (0)
		lst = va_arg(list, int);
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
	return (len);
}
