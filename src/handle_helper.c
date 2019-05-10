#include "ft_printf.h"

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

static int		conv_ex(int nb)
{
	if (nb >= 10)
		return (nb - 10 + 'a');
	else
		return (nb + '0');
}

char	*itoa_base3(int value, int base)
{
	int					i;
	char				*str;
	int				tmp;

	i = 0;
	tmp = value;
	while (tmp >= base)
	{
		tmp = tmp / base;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		tmp = value % base;
		str[i] = conv_ex(tmp);
		value /= base;
		i--;
	}
	return (str);
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

char *ft_strrev2(char *str)
{
	char tmp;
	int i;
	int len;

	tmp = 0;
	len = ft_strlen(str) - 1;
	i = 0;
	while (i < (len - i))
	{
		tmp = str[i];
		str[i] = str[len - i];
		str[len - i] = tmp;
		i++;
	}
	return(str);
}

char*	ft_itoa_fd_base2(unsigned long long n, int fd, int base, int upper) //fix -ve -o -x
{
	char * str;
	int n2;
	int i;

	str = ft_strnew(12);
	n2 = 0;
	i = 0;

	while (n >= 1) // or zero?
	{
		n2 = n % base;
		if (upper && n2 > 9)
			str[i] = (n2 + 'A' - 10);
		else if (n2 > 9)
			str[i] = (n2 + 'a' - 10);
		else
			str[i] = (n2 + '0');
		n = n / base;
		i++;
	}

	str[i++] = '\0';

	return(ft_strrev2(str)); //rev
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

int		ft_power(int nb, int power)
{
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	return (nb * ft_power(nb, power - 1));
}

long	ft_power_long(long nb, long pow)
{
	if (pow == 0)
		return (1);
	else if (pow < 0)
		return (0);
	return (nb * ft_power(nb, pow - 1));
}

long	ft_nbrlen(long nb, long base)
{
	long	length;

	length = 1;
	while (ft_power_long(base, length) <= nb)
		length++;
	return (length);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		length;
	char	temp;

	i = 0;
	length = ft_strlen(str);
	while (i < (length / 2))
	{
		temp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = temp;
		i++;
	}
	str[length] = '\0';
	return (str);
}

char	*ft_itoa_base2(int n, int base, int uppercase) //look into this...
{
	char	*str;
	int		i;
	int		length;

	if (base < 2 || base > 16 || (base != 10 && n < 0))
		return (NULL);
	if (base == 10)
		return (ft_itoa(n));
	length = ft_nbrlen(n, base);
	str = (char*)malloc(sizeof(*str) * (length + 1));
	i = 0;
	while (i < length)
	{
		if (base > 10 && (n % base >= 10) && uppercase)
			str[i++] = (n % base) - 10 + 'A';
		else if (base > 10 && (n % base >= 10))
			str[i++] = (n % base) - 10 + 'a';
		else
			str[i++] = (n % base) + '0';
		n /= base;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}

int ft_digilen(long long nb) // -ve doesn't count for precision but it does for width
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

int handle_sign(long long nb, char **convert, cv_table *argpart)
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

// int handle_precision2(char **convert, cv_table *argpart)
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

long long positive(long long nb)
{
 	if (nb < -9223372036854775807)
		return(9223372036854775807);
	if (nb < 0)
		return(nb * -1);
	else
		return(nb);
}

double positive2(double nb)
{
	if (nb < 0)
		return(nb * -1);
	else
		return(nb);
}

char * handle_zero(char *padding, cv_table *argpart)
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
			padding[i] = '\0';
		return(padding);
	}
	return(0);
}

char * handle_zero2(char *padding, cv_table *argpart)
{
	int i;

	i = 0;

	if(padding && argpart->zero_flag && !ft_strchr(argpart->flags, '-'))
	{
		while (padding[i] != '\0')
		{
			if (padding[i] == ' ')
				padding[i] = '0';
			i++;
		}
		if (ft_strchr(argpart->flags, ' '))
			padding[i] = '\0';
		return(padding);
	}
	return(0);
}

void handle_zeroes(char *padding, char **convert, cv_table *argpart)
{
	if (argpart->precision && argpart->specifier != '%')
	{
		handle_precision(convert, argpart);
	}
	else if (argpart->precision && argpart->specifier == '%')
	{
		if (ft_strchr(argpart->flags, '-'))
			*convert = ft_strjoin(*convert, ft_strnewchr(argpart->precision - 1, ' '));
		else
			*convert = ft_strjoin(ft_strnewchr(argpart->precision - 1, ' '), *convert);
	}
	else if (argpart->zero_flag && !ft_strchr(argpart->flags, '-') && !ft_strchr(argpart->conversions, '.'))
	{
		if ((padding = handle_zero(padding, argpart)))
		{
						*convert = ft_strjoin(padding, *convert);
						if (*padding == '0') //fixes
						 	*padding = '\0';
		}
	}
}

void handle_zeroes2(char *padding, char **convert, cv_table *argpart)
{
	if (argpart->precision && !argpart->zero_flag)
	{
		handle_precision(convert, argpart);
	}
	else if (argpart->zero_flag && !ft_strchr(argpart->flags, '-'))
	{
		if ((padding = handle_zero2(padding, argpart)))
		{
						*convert = ft_strjoin(padding, *convert);
						if (*padding == '0') //fixes
						 	*padding = '\0';
		}
	}
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

int ft_sign(long long d, cv_table *argpart)
{
	int ret = 0;
	int nve = ((d < 0) ? 1 : 0); // improve readability with the environmental function in the header
	int space = (ft_strchr(argpart->flags, ' ')) ? 1 : 0;
	int pve = (ft_strchr(argpart->flags, '+') && !nve) ? 1 : 0;

	ret = ((nve + pve + space) >= 1) ? 1 : 0;
	ret = ((argpart->specifier = '%') ? 0 : ret);
	return(ret);
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

char *ft_handle_width(long long nb, char * convert, cv_table *argpart)
{
	int sign = ft_sign(nb, argpart); //need to modify to work with oxX

	int len = MAX(ft_strlen(convert), argpart->precision);

	char *padding;
	if (argpart->width > argpart->precision)
	{
		int pflag;

		pflag = (argpart->specifier == 'p' ? 2 : 0);
		padding = ft_strnewchr(argpart->width - len - sign - pflag, ' ');
		if (padding)
			return(padding);
		else
			return("");
	}
	return("");
}

int handle_precision(char **convert, cv_table *argpart) //***********
{
	if (argpart->precision - ft_strlen(*convert) > 0)
	{
		char *newchr =  ft_strnewchr(argpart->precision - ft_strlen(*convert), '0');

		if (newchr)
			*convert = ft_strjoin(newchr, *convert);
	}
	return(0);
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

int	ft_number_len2(long long nb)
{
	int i;

	i = 1;
	while (nb < -9223372036854775807)
	{
		i++;
		nb = nb / 10;
	}
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static void	itoa_isnegative2(long long *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char		*ft_itoa2(long long n)
{
	int		len;
	int		negative;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	negative = 0;
	itoa_isnegative2(&n, &negative);
	len = ft_number_len2(n) + negative;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}

static int	places(unsigned long long n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		++count;
		n /= 16;
	}
	return (count);
}

char		*ft_ptoa(void *p, char c) // hanles max long long
{
	char				*s;
	unsigned long long	n;
	int					i;

	n = (unsigned long long)p;
	i = places(n);
	if (!(s = (char*)ft_memalloc(i + 1)))
		return (NULL);
	if (p == NULL)
		s[0] = '0';
	while (n)
	{
		s[--i] = (n % 16 > 9) ? (n % 16 - 10 + c) : (n % 16 + '0');
		n /= 16;
	}
	return (s);
}
