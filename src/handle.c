#include "../ft_printf.h"

int handle_s(va_list list, conversion_table *argpart)
{
	int len;
	char *str;

	len = 0;
	str = va_arg(list, char *);
	len = dup_put_char(ft_strlen(str), argpart->width, ' ') + ft_strlen(str);
	ft_putstr(str);
	return(len);
}

int handle_c(va_list list, conversion_table *argpart)
{
	int len;
	char ch;

	len = 0;
	ch = va_arg(list, int);
	if (ft_strchr(argpart->flags, '-'))
	{
		ft_putchar(ch);
		len = dup_put_char(1, argpart->width, ' ') + 1;
	}
	else
	{
		len = dup_put_char(1, argpart->width, ' ') + 1;
		ft_putchar(ch);
	}
	return(len);
}

int handle_d(va_list list, conversion_table *argpart)
{
	int len;
	int nb;
	int nve;
	int pve;
	int space;
	size_t digilen;
	int nveflag;

	len = 0;
	nb = va_arg(list, int);
	digilen = ft_digilen(nb);
	nve = ((nb < 0) ? 1 : 0);
	space = (ft_strchr(argpart->flags, ' ')) ? 1 : 0;
	pve = (ft_strchr(argpart->flags, '+') && nb > 0) ? 1 : 0;
	nveflag = (ft_strchr(argpart->flags, '-') && nb > 0) ? 1 : 0;

		if (nve)
			ft_putchar('-');
		if (pve)
			ft_putchar('+');
		else if (space)
			ft_putchar(' ');
		if (!nveflag)
			len = len + dup_put_char2(argpart->width - argpart->precision - digilen - nve - pve - space, ' ') + 1;
		len = dup_put_char2(argpart->precision - digilen, '0') + 1;
		if (nve)
			ft_putnbr(nb * -1);
		else
			ft_putnbr(nb);
		if (nveflag)
			len = len + dup_put_char2(argpart->width - argpart->precision - digilen - nve - pve - space, ' ') + 1;
		// printf("width %zu precision %zu digilen %zu\n", argpart->width, argpart->precision , digilen);

	return(len);
}

int handle_o(va_list list, conversion_table *argpart)
{
	unsigned int nb = va_arg(list, int);
	ft_putnbr_fd_base(nb, 1, 8, 0);
	return(1);
}

int handle_u(va_list list, conversion_table *argpart)
{
	unsigned int nb = va_arg(list, int);
	ft_putnbr_fd_base(nb, 1, 10, 0);
	return(1);
}

int handle_x(va_list list, conversion_table *argpart)
{
	unsigned int nb = va_arg(list, int);
	ft_putnbr_fd_base(nb, 1, 16, 0);
	return(1);
}

int handle_X(va_list list, conversion_table *argpart)
{
	unsigned int nb = va_arg(list, int);
	ft_putnbr_fd_base(nb, 1, 16, 1);
	return(1);
}

int handle_p(va_list list, conversion_table *argpart)
{
	unsigned long long nb = (unsigned long long)va_arg(list, void *);
	write(1,"0x",2);
	ft_putnbr_fd_base(nb, 1, 16, 0);
	return(1);
}

int call_handler(va_list list, conversion_table *argpart)
{
	int (*func[11])(va_list, conversion_table*);
	func[0] = handle_c;
	func[1] = handle_s;
	func[2] = handle_d;
	func[3] = handle_d;
	func[4] = handle_o;
	func[5] = handle_u;
	func[6] = handle_x;
	func[7] = handle_X;
	func[8] = handle_p;

	const char *keys = "csdiouxXp";
	int y = ft_strchr(keys, argpart->specifier) - keys;
	return(func[y](list, argpart));
}
