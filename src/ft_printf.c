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

int		valid_conversion(cv_table argpart, const char *format, va_list list)
{
	if (!ft_search(argpart.conversions, SPECI))
		return (0);
	return (1);
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
	write(1,format, str_len);
	return (str_len);
}

void	initalize(cv_table *argpart)
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
	cv_table	argpart;

	place = 0;
	printed = 0;
	initalize(&argpart);
	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{
			place = parse(&argpart, ++format);
			if (valid_conversion(argpart, format, list))
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
