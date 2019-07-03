/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimpkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:37:31 by lsimpkin          #+#    #+#             */
/*   Updated: 2018/11/29 16:37:32 by lsimpkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t	i;
	int		nb;

	i = 0;
	nb = 0;
	while ((s1[i] || s2[i]) && i < size)
	{
		if (s1[i] != s2[i])
		{
			nb = ((unsigned char)s1[i]) - (unsigned char)s2[i];
			return (nb);
		}
		i++;
	}
	return (0);
}
