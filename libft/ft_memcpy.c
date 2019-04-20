/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimpkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:26:31 by lsimpkin          #+#    #+#             */
/*   Updated: 2018/11/29 16:26:52 by lsimpkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ddst;
	unsigned char	*ssrc;

	i = 0;
	ddst = (unsigned char *)dst;
	ssrc = (unsigned char *)src;
	while (i < n)
	{
		ddst[i] = ssrc[i];
		i++;
	}
	return (ddst);
}
