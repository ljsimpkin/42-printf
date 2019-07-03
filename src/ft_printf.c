/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimpkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:25:52 by lsimpkin          #+#    #+#             */
/*   Updated: 2019/05/08 17:25:55 by lsimpkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_search(const char *str, char *search)
{
	int pt;

	pt = 0;
	while (*search)
	{
		if (ft_strchr(str, *search))
		{
			return (ft_strchr(str, *search));
		}
		search++;
	}
	return (0);
}

int		ft_sign(long long d, t_tab *argpart)
{
	int ret;
	int nve;
	int space;
	int pve;

	ret = 0;
	nve = ((d < 0) ? 1 : 0);
	space = (ft_strchr(argpart->flags, ' ')) ? 1 : 0;
	pve = (ft_strchr(argpart->flags, '+') && !nve) ? 1 : 0;
	ret = ((nve + pve + space) >= 1) ? 1 : 0;
	ret = ((argpart->specifier == '%') ? 0 : ret);
	return (ret);
}

int		ft_putbasic(const char *format, int *printed)
{
	char	*percent_ptr;
	int		str_len;

	percent_ptr = 0;
	str_len = 0;
	percent_ptr = ft_strchr(format, '%');
	if (percent_ptr)
		str_len = percent_ptr - format;
	else
		str_len = ft_strlen(format);
	*printed = *printed + str_len;
	write(1, format, str_len);
	return (str_len);
}

void	initalize(t_tab *argpart)
{
	argpart->conversions = 0;
	argpart->specifier = 0;
	argpart->flags = 0;
	argpart->error = 0;
	argpart->formatlen = 0;
	argpart->width = 0;
	argpart->precision = 0;
}

int		ft_printf(const char *format, ...)
{
	int			place;
	int			printed;
	va_list		list;
	t_tab		argpart;

	place = 0;
	printed = 0;
	initalize(&argpart);
	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{
			place = parse(&argpart, ++format);
			if (ft_search(argpart.conversions, SPECI))
			{
				printed = printed + call_handler(list, &argpart);
				format = place + format;
			}
		}
		else
			format = format + (ft_putbasic(format, &printed));
	}
	va_end(list);
	return (printed);
}
