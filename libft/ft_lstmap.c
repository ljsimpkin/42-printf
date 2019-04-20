/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimpkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:26:15 by lsimpkin          #+#    #+#             */
/*   Updated: 2018/12/12 13:26:17 by lsimpkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlst;
	t_list *temp;

	if (!lst)
		return (lst);
	temp = f(lst);
	if (temp == NULL)
		return (NULL);
	newlst = temp;
	while (lst->next)
	{
		lst = lst->next;
		temp->next = f(lst);
		if (temp->next == NULL)
		{
			ft_lstdel(&temp, ft_deln);
			return (NULL);
		}
		temp = temp->next;
	}
	temp->next = NULL;
	return (newlst);
}
