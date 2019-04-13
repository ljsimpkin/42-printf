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

int ft_digilen(int nb) // -ve doesn't count for precision but it does for width
{
	int len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
	}
	if (nb >= 0)
		len++;
	while (nb > 9)
	{
		nb = nb / 10;
		len++;
	}
	return(len);
}
