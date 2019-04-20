/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimpkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:44:24 by lsimpkin          #+#    #+#             */
/*   Updated: 2018/11/29 16:44:24 by lsimpkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_type(char l, char s)
{
	if (l == ' ' || l == '\t' || l == '\n' ||
	s == ' ' || l == '\0')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	int	strt;
	int	len;
	char*str;

	if (s == NULL)
		return (NULL);
	strt = 0;
	len = ft_strlen(s);
	if (s[strt] == '\0')
		return (ft_strdup(s + strt));
	while (s[strt] && ft_type(s[strt], s[strt]))
		strt++;
	while (len >= 0)
	{
		if (ft_type(s[len], s[strt]))
			len--;
		else
			break ;
	}
	if (strt > len)
		return (ft_strdup(""));
	str = ft_strsub(s, strt, len - strt + 1);
	if (!str)
		return (NULL);
	return (str);
}
