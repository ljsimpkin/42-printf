/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimpkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:20:59 by lsimpkin          #+#    #+#             */
/*   Updated: 2018/12/12 13:21:01 by lsimpkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **link, void (*del)(void *, size_t))
{
	t_list	*nx;

	nx = *link;
	while (nx)
	{
		nx = (*link)->next;
		ft_lstdelone(link, del);
		*link = nx;
	}
}
