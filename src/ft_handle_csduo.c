/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_csduo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimpkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 11:42:33 by lsimpkin          #+#    #+#             */
/*   Updated: 2019/06/18 11:42:35 by lsimpkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_c(va_list list, t_tab *argpart)
{
	char			c;

	c = va_arg(list, int);
	if (argpart->width && !(ft_strchr(argpart->flags, '-')))
	{
		if (argpart->zero_flag)
			ft_putnchar('0', argpart->width - 1);
		else
			ft_putnchar(' ', argpart->width - 1);
	}
	write(1, &c, 1);
	if (argpart->width && ft_strchr(argpart->flags, '-'))
	{
		if (argpart->zero_flag)
			ft_putnchar('0', argpart->width - 1);
		else
			ft_putnchar(' ', argpart->width - 1);
	}
	return (argpart->width ? argpart->width : 1);
}

int	handle_s(va_list list, t_tab *argpart)
{
	char	*str;
	char	*mod;

	str = va_arg(list, char *);
	if (!str)
		str = "(null)";
	mod = handle_strprecision(str, argpart);
	mod = handle_strwidth(mod, argpart);
	write(1, mod, ft_strlen(mod));
	return (ft_strlen(mod));
}

int	handle_d(va_list list, t_tab *argpart)
{
	int			len;
	long long	nb;
	char		*convert;
	char		*padding;
	char		*pt;

	len = 0;
	nb = handle_length(list, argpart);
	convert = ft_strnew(ft_number_len(nb));
	convert = ft_strcpy(convert, ft_itoa_base(positive(nb), 10, 0));
	padding = ft_handle_width(nb, convert, argpart);
	handle_zeroes(padding, &convert, argpart);
	handle_sign(nb, &convert, argpart);
	pt = convert;
	if (ft_strchr(argpart->flags, '-'))
		convert = ft_strjoin(pt, padding);
	else
		convert = ft_strjoin(padding, pt);
	len = ft_strlen(convert);
	write(1, convert, len);
	free(convert);
	free(pt);
	return (len);
}

int	handle_o(va_list list, t_tab *argpart)
{
	int						len;
	char					*padding;
	unsigned long long int	nb;
	char					*convert;
	char					*pt;

	len = 0;
	nb = unsigned_handle_length(list, argpart);
	convert = ft_strnew(ft_number_len(nb));
	convert = ft_strcpy(convert, ft_uns_itoa_base(nb, 8, 0));
	handle_hash(&convert, argpart);
	padding = ft_handle_width(nb, convert, argpart);
	handle_zeroes(padding, &convert, argpart);
	pt = convert;
	if (ft_strchr(argpart->flags, '-'))
		convert = ft_strjoin(pt, padding);
	else
		convert = ft_strjoin(padding, pt);
	len = ft_strlen(convert);
	write(1, convert, len);
	free(convert);
	free(pt);
	return (len);
}

int	handle_u(va_list list, t_tab *argpart)
{
	int						len;
	char					*padding;
	unsigned long long int	nb;
	char					*convert;
	char					*pt;

	len = 0;
	nb = unsigned_handle_length(list, argpart);
	convert = ft_strnew(ft_number_len(nb));
	convert = ft_strcpy(convert, ft_uns_itoa_base(nb, 10, 0));
	padding = ft_handle_width(nb, convert, argpart);
	handle_zeroes(padding, &convert, argpart);
	pt = convert;
	if (ft_strchr(argpart->flags, '-'))
		convert = ft_strjoin(pt, padding);
	else
		convert = ft_strjoin(padding, pt);
	len = ft_strlen(convert);
	write(1, convert, len);
	free(convert);
	free(pt);
	return (len);
}
