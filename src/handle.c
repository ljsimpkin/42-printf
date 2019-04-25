#include "ft_printf.h"

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
	return(len); // return len incuding width
}

long long int handle_length(va_list list, conversion_table *argpart)
{
	long long nb = va_arg(list, long long);
	if (argpart->lengths == 0) // INT
		return((long long) (int)nb);
	else if (argpart->lengths == HH) //SIGNED CHAR
	{
		nb = (char)nb;
		return((long long)nb);
	}
	else if (argpart->lengths == H) //SHORT INT
	{
		nb = (short int)nb;
		return((long long)nb);
	}
	else if (argpart->lengths == L) //LONG INT
	{
		nb = (long int)nb;
		return((long long)nb);
	}
	else //LONG LONG
		return (nb);
}

int handle_d(va_list list, conversion_table *argpart)
{
	int len = 0;
	long long nb = handle_length(list, argpart);
	char *convert = ft_strnew(ft_number_len2(nb));
	convert = ft_strcpy(convert, ft_itoa2(positive2(nb))); //fix ft_strcpy
	char *padding = ft_handle_width(nb, convert, argpart);
	handle_zeroes(padding, &convert, argpart);
	handle_sign(nb, &convert, argpart);

	if (ft_strchr(argpart->flags, '-'))
		convert = ft_strjoin(convert, padding);
	else
		convert = ft_strjoin(padding, convert);
	len = ft_strlen(convert);
 	write(1, convert, len);

	return(len);
}

void handle_hash(char **convert, conversion_table *argpart)
{
	if (argpart->specifier == 'o' && ft_strchr(argpart->flags, '#'))
		*convert = ft_strjoin("0", *convert);
	else if ((argpart->specifier == 'x' || argpart->specifier == 'X') && ft_strchr(argpart->flags, '#'))
		*convert = ft_strjoin("0x", *convert);
	else if (argpart->specifier == 'p')
		*convert = ft_strjoin("0x", *convert);
}

int handle_o(va_list list, conversion_table *argpart) //supposed to be signed?
{
	int len = 0;
	unsigned int nb = va_arg(list, int);
	char *convert = ft_strnew(ft_digilen(nb));
	convert = ft_strcpy(convert, ft_itoa_base(nb, 8)); //fix ft_strcpy
	handle_hash(&convert, argpart);
	char *padding = ft_handle_width(nb, convert, argpart);
	handle_zeroes(padding, &convert, argpart);

	if (ft_strchr(argpart->flags, '-'))
		convert = ft_strjoin(convert, padding);
	else
		convert = ft_strjoin(padding, convert);

	len = ft_strlen(convert);
 	write(1, convert, len);
	return(len);
}

int handle_u(va_list list, conversion_table *argpart)
{
	int len = 0;
	unsigned int nb = va_arg(list, int);
	char *convert = ft_strnew(ft_digilen(nb));
	convert = ft_strcpy(convert, ft_itoa_base(nb, 10)); //fix ft_strcpy
	char *padding = ft_handle_width(nb, convert, argpart);
	handle_zeroes(padding, &convert, argpart);

	if (ft_strchr(argpart->flags, '-'))
		convert = ft_strjoin(convert, padding);
	else
		convert = ft_strjoin(padding, convert);

	len = ft_strlen(convert);
 	write(1, convert, len);
	return(len);
}

int handle_x(va_list list, conversion_table *argpart)
{
	int len = 0;
	unsigned int nb = va_arg(list, int);
	char *convert = ft_strnew(ft_digilen(nb));
	convert = ft_strcpy(convert, ft_itoa_base2(nb, 16, 0)); //fix ft_strcpy
	handle_hash(&convert, argpart);
	char *padding = ft_handle_width(nb, convert, argpart);
	handle_zeroes(padding, &convert, argpart);

	if (ft_strchr(argpart->flags, '-'))
		convert = ft_strjoin(convert, padding);
	else
		convert = ft_strjoin(padding, convert);

	len = ft_strlen(convert);
 	write(1, convert, len);
	return(len);
}

int handle_X(va_list list, conversion_table *argpart)
{
	int len = 0;
	unsigned int nb = va_arg(list, int);
	char *convert = ft_strnew(ft_digilen(nb));
	convert = ft_strcpy(convert, ft_itoa_base2(nb, 16, 1)); //fix ft_strcpy
	handle_hash(&convert, argpart);
	char *padding = ft_handle_width(nb, convert, argpart);
	handle_zeroes(padding, &convert, argpart);

	if (ft_strchr(argpart->flags, '-'))
		convert = ft_strjoin(convert, padding);
	else
		convert = ft_strjoin(padding, convert);


	len = ft_strlen(convert);
 	write(1, convert, len);
	return(len);
}

int handle_p(va_list list, conversion_table *argpart)
{
	unsigned long long nb = (unsigned long long)va_arg(list, void *);
	int len = 0;
	char *convert = ft_strnew(ft_digilen(nb));
	convert = ft_strcpy(convert, ft_itoa_fd_base2(nb, 1, 16, 0)); //fix ft_strcpy
	char *padding = ft_handle_width(nb, convert, argpart);
	handle_zeroes(padding, &convert, argpart);
	handle_hash(&convert, argpart);

	if (ft_strchr(argpart->flags, '-'))
		convert = ft_strjoin(convert, padding);
	else
		convert = ft_strjoin(padding, convert);

	len = ft_strlen(convert);
 	write(1, convert, len);
	return(len);
	return(1);
}

long double	float_handle_mod(va_list list, conversion_table *argpart)
{
	long double f;

	if (argpart->lengths == 5 || argpart->lengths == 3) //assuming lowercase l = long double too
		f = va_arg(list, long double);
	else
		f = (double)va_arg(list, double);
	return (f);
}

int float_len(long double nb)
{
	int tmp;
	int count;

	tmp = 0;
	count = 0;
	while (nb > 1)
		nb /= 10;

	while (nb)
	{
		nb *= 10;
		nb = nb - (int)nb;
		count++;
	}
	return(count);
}

long double rounding(double nb, conversion_table *argpart)
{
	int i;
	double rd;
	int precision;
	int sign;

	sign = (nb < 0) ? 1 : 0;

	i = 0;
	precision = argpart->precision ? argpart->precision : 6;

	if (ft_strchr(argpart->conversions, '.') && precision == 6 && argpart->precision == 0)
		precision = 0;

	rd = 5;

	while (i <= precision)
	{
		rd /= 10;
		i++;
	}

	nb = sign ? nb - rd : nb + rd;

	return(nb);
}

char *fractional(long double nb, conversion_table *argpart)
{
	int i = 0;
	int fracint = 0;
	int precision = (argpart->precision || ft_strchr(argpart->conversions, '.')) ? argpart->precision : 6;
	long double frac = nb - (int)nb;
	if (frac < 0)
		frac *= -1;
	char *str = malloc(sizeof(char) * precision + 3);
	if (precision)
		str[i] = '.';
	while (i < precision + 1)
	{
		i++;
		frac *= 10;
		fracint = (int)(frac);
		str[i] = (fracint + '0');
		frac = frac - fracint;
	}
	str[i] = '\0';
	return(str);
}

int handle_f(va_list list, conversion_table *argpart)
{
	double nb = float_handle_mod(list, argpart);
	nb = rounding(nb, argpart);
	char *integ = ft_itoa(positive((int)nb));
	char *frac = fractional(nb, argpart);
	char *convert = ft_strjoin(integ, frac);
	char *padding = ft_handle_width(nb, convert, argpart);
	// handle_zero2(padding, argpart);
	handle_zeroes2(padding, &convert, argpart);
	handle_sign(nb, &convert, argpart);

	if (ft_strchr(argpart->flags, '-'))
		convert = ft_strjoin(convert, padding);
	else
		convert = ft_strjoin(padding, convert);

	int len = ft_strlen(convert);
	write(1, convert, len);
	return(1);
 }

 int handle_percent(va_list list, conversion_table *argpart)
 {
	int len = 0;
	char * convert = ft_strdup("%"); //fix ft_strcpy
 	char *padding = ft_handle_width(1, convert, argpart);
 	handle_zeroes(padding, &convert, argpart);
 	// handle_sign(nb, &convert, argpart);

 	if (ft_strchr(argpart->flags, '-'))
 		convert = ft_strjoin(convert, padding);
 	else
 		convert = ft_strjoin(padding, convert);
 	len = ft_strlen(convert);
  	write(1, convert, len);
	 return(1);
 }



int call_handler(va_list list, conversion_table *argpart)
{
	int (*func[12])(va_list, conversion_table*);
	func[0] = handle_c;
	func[1] = handle_s;
	func[2] = handle_d;
	func[3] = handle_d;
	func[4] = handle_o;
	func[5] = handle_u;
	func[6] = handle_x;
	func[7] = handle_X;
	func[8] = handle_p;
	func[9] = handle_f;
	func[10]= handle_percent;

	const char *keys = "csdiouxXpf%";
	int y = ft_strchr(keys, argpart->specifier) - keys;
	return(func[y](list, argpart));
}
