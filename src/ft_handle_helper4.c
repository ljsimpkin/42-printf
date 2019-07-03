/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_helper4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimpkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 10:27:01 by lsimpkin          #+#    #+#             */
/*   Updated: 2019/06/19 10:27:03 by lsimpkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long long	positive(long long nb)
{
	if (nb < -9223372036854775807)
		return (9223372036854775807);
	if (nb < 0)
		return (nb * -1);
	else
		return (nb);
}

char		*ft_strrev(char *buff, int len)
{
	int		i;
	char	*ret;

	ret = malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = buff[len - i - 1];
		i++;
	}
	ret[len] = '\0';
	return (ret);
}

char		*ft_itoa_base(long long value, int base, int uppercase)
{
	int			negative;
	char		buff[33];
	int			len;

	negative = 0;
	if ((base == 10) && value < 0)
		negative = 1;
	len = 0;
	while (value || len == 0)
	{
		if (uppercase)
			buff[len] = g_base[(value % base)];
		else
			buff[len] = g_lowr[(value % base)];
		len++;
		value /= base;
	}
	if (negative && base == 10)
	{
		buff[len] = '-';
		len++;
	}
	return (ft_strrev(buff, len));
}

char		*ft_uns_itoa_base(unsigned long long value, int base, int uppercase)
{
	char		buff[33];
	int			len;

	len = 0;
	while (value || len == 0)
	{
		if (uppercase)
			buff[len] = g_base[(value % base)];
		else
			buff[len] = g_lowr[(value % base)];
		len++;
		value /= base;
	}
	return (ft_strrev(buff, len));
}

char		*handle_strzeroes(char *convert, t_tab *argpart)
{
	int		hash;
	char	*str;

	hash = ft_strchr(argpart->flags, '#') ? 2 : 0;
	argpart->len = ft_strlen(convert);
	if (hash)
		hash = (convert[0] == '0' && convert[1] == '\0') ? 0 : 2;
	if ((argpart->len + hash) < (int)argpart->width && argpart->zero_flag
	&& !ft_strchr(argpart->flags, '-') && !ft_strchr(argpart->conversions, '.'))
	{
		str = ft_strdupchr(argpart->width - argpart->len - hash, '0');
		return (ft_strjoin(str, convert));
	}
	return (convert);
}
