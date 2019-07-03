/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimpkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:46:31 by lsimpkin          #+#    #+#             */
/*   Updated: 2018/11/29 16:46:32 by lsimpkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t y;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] && i <= len)
	{
		y = 0;
		while (needle[y] == haystack[i + y])
		{
			if ((i + y) == len)
				return (NULL);
			if (needle[y + 1] == '\0' || (i + y) == len)
			{
				return ((char *)haystack + i);
			}
			y++;
		}
		i++;
	}
	return (NULL);
}
