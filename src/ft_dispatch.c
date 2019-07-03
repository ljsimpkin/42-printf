/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimpkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 11:38:37 by lsimpkin          #+#    #+#             */
/*   Updated: 2019/06/18 11:38:41 by lsimpkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int			handle_length(va_list list, t_tab *argpart)
{
	long long nb;

	nb = va_arg(list, long long);
	if (argpart->lengths == 0)
	{
		nb = (long long)(int)nb;
		return (nb);
	}
	else if (argpart->lengths == HH)
	{
		nb = (char)nb;
		return ((long long)nb);
	}
	else if (argpart->lengths == H)
	{
		nb = (short int)nb;
		return ((long long)nb);
	}
	else if (argpart->lengths == L)
	{
		nb = (long int)nb;
		return ((long long)nb);
	}
	else
		return (nb);
}

unsigned long long int	unsigned_handle_length(va_list list, t_tab *argpart)
{
	unsigned long long int n;

	if (argpart->lengths == LL)
		n = va_arg(list, unsigned long long);
	else if (argpart->lengths == L)
		n = va_arg(list, unsigned long);
	else if (argpart->lengths == H)
		n = (unsigned short int)va_arg(list, unsigned int);
	else if (argpart->lengths == HH)
		n = (unsigned char)va_arg(list, unsigned int);
	else
		n = (unsigned int)va_arg(list, unsigned int);
	return (n);
}

int						call_handler(va_list list, t_tab *argpart)
{
	int			y;
	const char	*keys = "csdiouxXpf%";
	int			(*func[12])(va_list, t_tab*);

	func[0] = handle_c;
	func[1] = handle_s;
	func[2] = handle_d;
	func[3] = handle_d;
	func[4] = handle_o;
	func[5] = handle_u;
	func[6] = handle_x;
	func[7] = handle_cap_x;
	func[8] = handle_p;
	func[9] = handle_f;
	func[10] = handle_percent;
	y = ft_strchr(keys, argpart->specifier) - keys;
	return (func[y](list, argpart));
}
