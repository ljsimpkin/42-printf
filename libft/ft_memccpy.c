/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimpkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:44:44 by lsimpkin          #+#    #+#             */
/*   Updated: 2018/11/29 16:15:39 by lsimpkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*srce;
	size_t			i;

	i = 0;
	dest = (unsigned char *)dst;
	srce = (unsigned char *)src;
	while (i < n)
	{
		dest[i] = srce[i];
		if (srce[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
