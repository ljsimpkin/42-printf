#include "../ft_printf.h"

int handle_s(va_list list, conversion_table *argpart)
{
	int len;
	char *str;

	len = 0;
	str = va_arg(list, char *);
	len = dup_put_char(ft_strlen(str), argpart->width, ' ') + ft_strlen(str);
	ft_putstr(str); //faster using the write function and len?
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
	int d = va_arg(list, int);
	char *convert = ft_strnew(ft_digilen(d));
	convert = strcpy(convert, ft_itoa(positive(d))); //fix ft_strcpy
	char *padding = ft_handle_width(d, convert, argpart);
	handle_zeroes(padding, &convert, argpart);
	handle_sign(d, &convert, argpart);

	if (ft_strchr(argpart->flags, '-'))
		convert = ft_strjoin(convert, padding);
	else
		convert = ft_strjoin(padding, convert);

 	write(1, convert, ft_strlen(convert));
	return(0);
}

int handle_o(va_list list, conversion_table *argpart)
{
	unsigned int o = va_arg(list, int);
	char *convert = ft_strnew(ft_digilen(o));
	convert = ft_strcpy(convert, ft_itoa_base(o, 8)); //fix ft_strcpy
	char *padding = ft_handle_width(o, convert, argpart);
	handle_zeroes(padding, &convert, argpart);
	// printf("padding = |%s|\n", padding);

	// handle_one(argpart, &padding);
	// printf("convert = |%s|\n", convert);
	// printf("padding = |%s|\n", padding);

	if (ft_strchr(argpart->flags, '-'))
		convert = ft_strjoin(convert, padding);
	else
		convert = ft_strjoin(padding, convert);

	write(1, convert, ft_strlen(convert));
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
