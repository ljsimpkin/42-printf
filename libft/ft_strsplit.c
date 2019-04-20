/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimpkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:43:37 by lsimpkin          #+#    #+#             */
/*   Updated: 2018/11/29 16:43:38 by lsimpkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	int	i;
	int	word;
	int	word_len;
	char**str;

	i = 0;
	word = 0;
	if (!s || \
		!(str = (char **)malloc(sizeof(char*) * (ft_word_count(s, c) + 1))))
		return (NULL);
	while (word < ft_word_count(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		word_len = ft_word_len(s, c, i);
		str[word] = ft_strsub(s, i, (word_len));
		if (str[word] == NULL)
			return (NULL);
		i = i + word_len;
		word++;
	}
	str[word] = NULL;
	return (str);
}
