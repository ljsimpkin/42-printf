/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimpkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:26:31 by lsimpkin          #+#    #+#             */
/*   Updated: 2019/05/08 17:26:32 by lsimpkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_conversions(cv_table *argpart, const char *format)
{
	int i;
	int size;

	i = 0;
	argpart->formatlen = ft_strlen(format);
	size = argpart->formatlen + 1;
	argpart->conversions = (char *)malloc(sizeof(char) * size);
	ft_bzero(argpart->conversions, argpart->formatlen);

	while (*format && !ft_strchr(SPECI, *format))
	{
		argpart->conversions[i] = *format;
		format++;
		i++;
	}
	argpart->conversions[i] = *format;
	argpart->conversions[i + 1] = '\0';
}

void	parse_flags(cv_table *argpart, const char *format)
{
	int i;
	int y;

	i = 0;
	y = 0;
	argpart->flags = ft_strnew(argpart->formatlen + 1);
	while (argpart->conversions[i])
	{
		if (ft_strchr(FLAGS, argpart->conversions[i]))
		{
			argpart->flags[y] = argpart->conversions[i];
			y++;
		}
		i++;
	}
	argpart->flags[i] = '\0';
}

int		parse_zeroflag(cv_table *argpart, const char *format)
{
	int i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '0')
			return (1);
		else if (ft_strchr("123456789", format[i]))
			return (0);
		i++;
	}
	return (0);
}

int		parse_lengths(cv_table *argpart, const char *format)
{
	char *pt;

	pt = 0;
	if ((pt = ft_strchr(format, 'h')))
	{
		if (*(pt + 1) == 'h')
			argpart->lengths = 1;
		else
			argpart->lengths = 2;
	}
	else if (((pt = ft_strchr(format, 'l'))))
	{
		if (*(pt + 1) == 'l')
			argpart->lengths = 4;
		else
			argpart->lengths = 3;
	}
	else if (((pt = ft_strchr(format, 'L'))))
		argpart->lengths = 5;
	else
		argpart->lengths = 0;

	return (0);
}

int		parse(cv_table *argpart, const char *format)
{
	parse_conversions(argpart, format);
	char *specifier;

	specifier = (ft_search(SPECI, argpart->conversions));
	if (specifier)
		argpart->specifier = *specifier;

	parse_flags(argpart, format);
	argpart->zero_flag = parse_zeroflag(argpart, format);
	argpart->width = ft_atoi_skip(format);

	if (ft_strchr(format, '.'))
		argpart->precision = ft_atoi_skip(ft_strchr(format, '.') + 1);

	parse_lengths(argpart, format);
	return (ft_strlen(argpart->conversions));
}
