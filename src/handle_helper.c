#include "../ft_printf.h"

static int	ft_isblank(const char *str, int i)
{
	while (*(str + i) == '\n' ||
		*(str + i) == '\t' ||
		*(str + i) == '\r' ||
		*(str + i) == '\v' ||
		*(str + i) == '\f' ||
		*(str + i) == ' '  ||
		*(str + i) == '-'  ||
		*(str + i) == '#'  ||
		*(str + i) == '+')
		i++;
	return (i);
}

int			ft_atoi_skip(const char *s) // include max int?
{
	int			i;
	int			n;

	n = 0;
	i = 0;
	i = ft_isblank(s, i);

	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		n = (10 * n) + (s[i] - '0');
		i++;
	}
	return (n);
}

void	ft_putnbr_fd_base(unsigned long long n, int fd, int base, int upper) //fix -ve -o -x
{
	if (n >= base)
		ft_putnbr_fd_base(n / base, fd, base, upper);
	n = n % base;
	if (upper && n > 9)
		ft_putchar_fd(n + 'A' - 10, fd);
	else if (n > 9)
		ft_putchar_fd(n + 'a' - 10, fd);
	else
		ft_putchar_fd(n + '0', fd);
}
static void	itoa_isnegative(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char		*ft_itoa_base(int n, int base)
{
	int		len;
	int		negative;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	negative = 0;
	itoa_isnegative(&n, &negative);
	len = ft_number_len(n) + negative;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = n % base + '0';
		n = n / base;
	}
	if (negative)
		str[0] = '-';
	return (str);
}

int ft_digilen(int nb) // -ve doesn't count for precision but it does for width
{
	int len;

	len = 0;
	if (nb < 0)
		nb = nb * -1;
	if (nb >= 0)
		len++;
	while (nb > 9)
	{
		nb = nb / 10;
		len++;
	}
	return(len);
}

int handle_sign(int nb, char **convert, conversion_table *argpart)
{
	int nve;
	int space;
	int pve;
	int nps;
	int i;

	i = 0;
	nve = ((nb < 0) ? 1 : 0); // improve readability with the environmental function in the header
	space = (ft_strchr(argpart->flags, ' ')) ? 1 : 0;
	pve = (ft_strchr(argpart->flags, '+') && nb > 0) ? 1 : 0;

	if (nve)
		 *convert = ft_strjoin("-", *convert); //must be placed before precision //free memory
	else if (pve)
		 *convert = ft_strjoin("+", *convert);
	else if (space) //space is ignored when pve is present
		 *convert = ft_strjoin(" ", *convert);

	return(ft_strlen(*convert));

}

// int handle_precision2(char **convert, conversion_table *argpart)
// {
// 	int precisionlen;
// 	char *precision;
//
// 	precisionlen =  argpart->precision - argpart->len; //could handle o flag in precision argpart->precision + argpart->zero_flag - argpart->len;
// 	if (precisionlen > 0)
// 	{
// 		precision = ft_strnew(precisionlen + 1);
//
// 		while (precisionlen--)
// 			precision[precisionlen] = '0';
//
// 		*convert = ft_strjoin(precision, *convert); //free convert before?
// 	}
// 	return(ft_strlen(*convert));
// }

int positive(int nb)
{
	if (nb < 0)
		return(nb * -1);
	else
		return(nb);
}

char * handle_zero(char *padding, conversion_table *argpart)
{
	int i;

	i = 0;

	if(padding && !argpart->precision && argpart->zero_flag &&!ft_strchr(argpart->flags, '-') && !ft_strchr(argpart->conversions, '.'))
	{
		while (padding[i] != '\0')
		{
			if (padding[i] == ' ')
				padding[i] = '0';
			i++;
		}
		if (ft_strchr(argpart->flags, ' '))
			padding[--i] = '\0';
		return(padding);
	}
	return(0);
}

int remove_dupsign(char *convert)
{
	char *pt;

	pt = convert;

	while (*pt)
	{
		pt++;
		if (*pt == '+' || *pt == '-' || *pt == ' ')
			*pt = '0';
	}
	return(1);
}

int ft_sign(int d, conversion_table *argpart)
{
	int nve = ((d < 0) ? 1 : 0); // improve readability with the environmental function in the header
	int space = (ft_strchr(argpart->flags, ' ')) ? 1 : 0;
	int pve = (ft_strchr(argpart->flags, '+') && !nve) ? 1 : 0;

	return(((nve + pve + space) >= 1) ? 1 : 0);
}

char *ft_strnewchr(int len, char c)
{
	if (len > 0)
	{
		char *str = (char*)malloc(sizeof(char) * len + 1);
		str[len] = '\0';
		while (len >= 0)
		{
			len--;
			str[len] = c;
		}
		return(str);
	}
	return(0);
}

char *ft_handle_width(int nb, char * convert, conversion_table *argpart)
{
	int sign = ft_sign(nb, argpart); //need to modify to work with oxX

	int len = MAX(ft_strlen(convert), argpart->precision);

	char *padding;
	if (argpart->width > argpart->precision)
	{
		padding = ft_strnewchr(argpart->width - len - sign, ' ');
		return(padding);
	}
	return("");
}

int handle_precision(char **convert, conversion_table *argpart)
{
	if (argpart->precision - ft_strlen(*convert) > 0)
		*convert = ft_strjoin(ft_strnewchr(argpart->precision - ft_strlen(*convert), '0'), *convert);
	return(0);
}

void handle_zeroes(char *padding, char **convert, conversion_table *argpart)
{
	if (argpart->precision)
	{
		handle_precision(convert, argpart);
	}
	else if (argpart->zero_flag && !ft_strchr(argpart->flags, '-') && !ft_strchr(argpart->conversions, '.'))
	{
		if ((padding = handle_zero(padding, argpart)))
		{
						*convert = ft_strjoin(padding, *convert);
						// *padding = '\0';
		}
	}
}

int dup_put_char(int len, int width, int ch) //precision combine and just return length
{
	if (width > len) // and no -
	{
		while (width - len)
		{
			ft_putchar(ch);
			width--;
		}
		return(width - len);
	}
	else
		return(0);
}

int dup_put_char2(int len, int ch) //precision combine and just return length
{
	if (len > 0) // and no -
	{
		while (len)
		{
			ft_putchar(ch);
			len--;
		}
		return(1);
	}
	else
		return(0);
}
