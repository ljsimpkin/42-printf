/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimpkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:12:06 by lsimpkin          #+#    #+#             */
/*   Updated: 2018/12/12 13:12:08 by lsimpkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list1;

	list1 = (t_list *)malloc(sizeof(t_list));
	if (list1 == NULL)
		return (NULL);
	if (content == NULL)
	{
		list1->content = NULL;
		list1->content_size = 0;
	}
	else
	{
		list1->content = malloc(sizeof(content) * content_size);
		if (list1->content == NULL)
			return (NULL);
		ft_memcpy((list1->content), content, content_size);
		list1->content_size = content_size;
	}
	list1->next = NULL;
	return (list1);
}
