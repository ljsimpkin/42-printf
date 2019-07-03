/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimpkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:43:57 by lsimpkin          #+#    #+#             */
/*   Updated: 2018/11/29 16:43:59 by lsimpkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int y;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i])
	{
		y = 0;
		while (needle[y] == haystack[i + y])
		{
			if (needle[y + 1] == '\0')
			{
				return ((char *)haystack + i);
			}
			y++;
		}
		i++;
	}
	return (0);
}
