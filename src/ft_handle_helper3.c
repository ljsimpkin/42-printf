/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_helper3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimpkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 10:23:52 by lsimpkin          #+#    #+#             */
/*   Updated: 2019/06/19 10:23:54 by lsimpkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strdupchr(int len, char c)
{
	char *str;

	if (len > 0)
	{
		str = (char*)malloc(sizeof(char) * len + 1);
		str[len] = '\0';
		while (len >= 0)
		{
			len--;
			str[len] = c;
		}
		return (str);
	}
	return (0);
}

void		handle_hash(char **convert, t_tab *argpart)
{
	if (argpart->specifier == 'o' && ft_strchr(argpart->flags, '#')
	&& (*convert[0] != '0'))
		*convert = ft_strjoin("0", *convert);
	else if ((argpart->specifier == 'x')
	&& ft_strchr(argpart->flags, '#')
	&& (ft_search("123456789abcdefABCDEF", *convert)))
		*convert = ft_strjoin("0x", *convert);
	else if ((argpart->specifier == 'X') &&
		ft_strchr(argpart->flags, '#')
		&& (ft_search("123456789abcdefABCDEF", *convert)))
		*convert = ft_strjoin("0X", *convert);
	else if (argpart->specifier == 'p')
		*convert = ft_strjoin("0x", *convert);
}

static int	ft_isblank(const char *str, int i)
{
	while (*(str + i) == '\n' ||
		*(str + i) == '\t' ||
		*(str + i) == '\r' ||
		*(str + i) == '\v' ||
		*(str + i) == '\f' ||
		*(str + i) == ' ' ||
		*(str + i) == '-' ||
		*(str + i) == '#' ||
		*(str + i) == '+' ||
		*(str + i) == '0')
		i++;
	return (i);
}

int			ft_atoi_skip(const char *s)
{
	int			i;
	int			n;

	n = 0;
	i = 0;
	i = ft_isblank(s, i);
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		n = (10 * n) + (s[i] - '0');
		i++;
	}
	return (n);
}

int			handle_sign(long long nb, char **convert, t_tab *argpart)
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
