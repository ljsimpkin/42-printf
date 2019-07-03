/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_helper2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimpkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 10:20:14 by lsimpkin          #+#    #+#             */
/*   Updated: 2019/06/19 10:20:17 by lsimpkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_strprecision(char *str, t_tab *argpart)
{
	int		len;
	char	*mod;

	len = ft_strlen(str);
	if (ft_strchr(argpart->conversions, '.') && len > (int)argpart->precision)
	{
		mod = ft_strnew(argpart->precision);
		mod = ft_strncpy(mod, str, argpart->precision);
	}
	else
	{
		mod = ft_strdup(str);
	}
	return (mod);
}

int		handle_precision(char **convert, t_tab *argpart)
{
	char *newchr;

	if (argpart->precision > ft_strlen(*convert))
	{
		newchr = ft_strdupchr(argpart->precision - ft_strlen(*convert), '0');
		if (newchr)
			*convert = ft_strjoin(newchr, *convert);
	}
	else if (argpart->precision == 0)
	{
		if (!(argpart->specifier == 'o' && ft_strchr(argpart->flags, '#')
		&& (ft_strchr(argpart->conversions, '.')
		&& argpart->precision == 0)) && *convert[0] == '0')
			*convert[0] = '\0';
	}
	return (0);
}

char	*handle_nbprecision(char *str, t_tab *argpart)
{
	int		len;
	char	*mod;

	len = ft_strlen(str);
	if (ft_strchr(argpart->conversions, '.') && len < (int)argpart->precision)
	{
		ft_putstr("2");
		mod = ft_strdupchr(argpart->precision, '0');
		mod = ft_strcpy(mod + (argpart->precision - len - 1), str);
	}
	else
	{
		mod = ft_strdup(str);
	}
	return (mod);
}

char	*handle_pprecision(char *convert, t_tab *argpart)
{
	int		len;
	char	*prec;

	len = ft_strlen(convert);
	if (len < (int)argpart->precision)
	{
		prec = ft_strdupchr(argpart->precision - len, '0');
		return (ft_strjoin(prec, convert));
	}
	else if (convert[0] == '0' && ft_strchr(argpart->conversions, '.')
	&& argpart->precision == 0)
		convert = strdup("\0");
	return (convert);
}

char	*handle_strwidth(char *mod, t_tab *argpart)
{
	int		len;
	char	*wide;

	len = ft_strlen(mod);
	if (len < (int)argpart->width)
	{
		wide = ft_strdupchr(argpart->width - len, ' ');
		if (ft_strchr(argpart->flags, '-'))
			mod = ft_strjoin(mod, wide);
		else
			mod = ft_strjoin(wide, mod);
		free(wide);
	}
	return (mod);
}
