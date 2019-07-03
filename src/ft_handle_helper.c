/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimpkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 11:43:15 by lsimpkin          #+#    #+#             */
/*   Updated: 2019/06/18 11:43:17 by lsimpkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*handle_zero(char *padding, t_tab *argpart)
{
	int i;

	i = 0;
	if (padding && !argpart->precision && argpart->zero_flag &&
	!ft_strchr(argpart->flags, '-') && !ft_strchr(argpart->conversions, '.'))
	{
		while (padding[i] != '\0')
		{
			if (padding[i] == ' ')
				padding[i] = '0';
			i++;
		}
		return (padding);
	}
	return (0);
}

char	*handle_zero2(char *padding, t_tab *argpart)
{
	int i;

	i = 0;
	if (padding && argpart->zero_flag && !ft_strchr(argpart->flags, '-'))
	{
		while (padding[i] != '\0')
		{
			if (padding[i] == ' ')
				padding[i] = '0';
			i++;
		}
		return (padding);
	}
	return (0);
}

void	handle_zeroes(char *padding, char **convert, t_tab *argpart)
{
	char *tmp;

	if (ft_strchr(argpart->conversions, '.') && argpart->specifier != '%')
		handle_precision(convert, argpart);
	else if (argpart->precision && argpart->specifier == '%')
	{
		if (ft_strchr(argpart->flags, '-'))
		{
			tmp = ft_strdupchr(argpart->precision - 1, ' ');
			*convert = ft_strjoin(*convert, tmp);
		}
		else
		{
			tmp = ft_strdupchr(argpart->precision - 1, ' ');
			*convert = ft_strjoin(tmp, *convert);
		}
	}
	else if (argpart->zero_flag && !ft_strchr(argpart->flags, '-')
	&& !ft_strchr(argpart->conversions, '.'))
		if ((padding = handle_zero(padding, argpart)))
		{
			*convert = ft_strjoin(padding, *convert);
			if (*padding)
				*padding = (*padding == '0') ? '\0' : *padding;
		}
}

void	handle_zeroes2(char *padding, char **convert, t_tab *argpart)
{
	if (argpart->precision && !argpart->zero_flag)
	{
		handle_precision(convert, argpart);
	}
	else if (argpart->zero_flag && !ft_strchr(argpart->flags, '-'))
	{
		if ((padding = handle_zero2(padding, argpart)))
		{
			*convert = ft_strjoin(padding, *convert);
			if (*padding == '0')
				*padding = '\0';
		}
	}
}

char	*ft_handle_width(long long nb, char *convert, t_tab *argpart)
{
	int		sign;
	int		len;
	char	*padding;
	int		pflag;

	len = MAX(ft_strlen(convert), argpart->precision);
	sign = ft_sign(nb, argpart);
	if (nb == 0 && argpart->precision == 0 &&
	ft_strchr(argpart->conversions, '.') && !ft_strchr(argpart->flags, '#'))
		len = 0;
	if (argpart->width > argpart->precision)
	{
		pflag = (argpart->specifier == 'p' ? 2 : 0);
		padding = ft_strdupchr(argpart->width - len - sign - pflag, ' ');
		if (padding)
			return (padding);
		else
			return ("");
	}
	return ("");
}
