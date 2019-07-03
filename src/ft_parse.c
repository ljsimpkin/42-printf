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

void	parse_conversions(t_tab *argpart, const char *conversions)
{
	int i;
	int size;

	i = 0;
	argpart->formatlen = ft_strlen(conversions);
	size = argpart->formatlen + 1;
	argpart->conversions = (char *)malloc(sizeof(char) * size);
	ft_bzero(argpart->conversions, argpart->formatlen);
	while (*conversions && !ft_strchr(SPECI, *conversions))
	{
		argpart->conversions[i] = *conversions;
		conversions++;
		i++;
	}
	argpart->conversions[i] = *conversions;
	argpart->conversions[i + 1] = '\0';
}

void	parse_flags(t_tab *argpart)
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

int		parse_zeroflag(const char *conversions)
{
	int i;

	i = 0;
	while (conversions[i])
	{
		if (conversions[i] == '0')
			return (1);
		else if (ft_strchr("123456789", conversions[i]))
			return (0);
		i++;
	}
	return (0);
}

int		parse_lengths(t_tab *argpart, const char *conversions)
{
	char *pt;

	pt = 0;
	if ((pt = ft_strchr(conversions, 'h')))
	{
		if (*(pt + 1) == 'h')
			argpart->lengths = 1;
		else
			argpart->lengths = 2;
	}
	else if (((pt = ft_strchr(conversions, 'l'))))
	{
		if (*(pt + 1) == 'l')
			argpart->lengths = 4;
		else
			argpart->lengths = 3;
	}
	else if (((pt = ft_strchr(conversions, 'L'))))
		argpart->lengths = 5;
	else
		argpart->lengths = 0;
	return (0);
}

int		parse(t_tab *argpart, const char *format)
{
	char *pt;
	char *specifier;

	parse_conversions(argpart, format);
	specifier = (ft_search(SPECI, argpart->conversions));
	if (specifier)
		argpart->specifier = *specifier;
	parse_flags(argpart);
	argpart->zero_flag = parse_zeroflag(argpart->conversions);
	argpart->width = ft_atoi_skip(argpart->conversions);
	if (ft_strchr(argpart->conversions, '.'))
	{
		pt = ft_strchr(argpart->conversions, '.');
		argpart->precision = ft_atoi_skip(pt + 1);
	}
	parse_lengths(argpart, argpart->conversions);
	return (ft_strlen(argpart->conversions));
}
