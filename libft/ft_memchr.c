/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimpkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:26:00 by lsimpkin          #+#    #+#             */
/*   Updated: 2018/11/29 16:26:01 by lsimpkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ddst;

	i = 0;
	ddst = (unsigned char *)s;
	while (i < n)
	{
		if (ddst[i] == (unsigned char)c)
			return (ddst + i);
		i++;
	}
	return (NULL);
}
