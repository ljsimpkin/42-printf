#include "ft_printf.h"

int main()
{
	char *str  = "a";
	char c = 'a';
	// ft_printf("str = |%s",str);
	// ft_printf("str = |%d|\n", 42);
	// printf("str = |%d|\n", 42);
	printf("prif |%5.43d| after\n", -42);
	ft_printf("test |%5.43d| after\n", -42);

	return(0);

}

// int handle_d(va_list list, conversion_table *argpart)
// {
// 	int len;
// 	int nb;
// 	int nve;
// 	int pve;
// 	int space;
// 	size_t digilen;
// 	int nveflag;
// 	int padding;
// 	int nps;
// 	int maxpd;
//
// 	len = 0;
// 	nb = va_arg(list, int);
// 	nve = ((nb < 0) ? 1 : 0); // improve readability with the environmental function in the header
// 	space = (ft_strchr(argpart->flags, ' ')) ? 1 : 0;
// 	pve = (ft_strchr(argpart->flags, '+') && nb > 0) ? 1 : 0;
// 	nveflag = (ft_strchr(argpart->flags, '-') && nb > 0) ? 1 : 0; // why nb > 0?
// 	nps = ((nve + pve + space) >= 1) ? 1 : 0;
// 	digilen = ft_digilen(nb);
// 	maxpd = (argpart->precision > digilen) ? argpart->precision : digilen;
// 	padding = argpart->width - maxpd - nps;
//
// 		// printf("padding = %d\n", padding);
// 		// printf("width = %zu, precision = %zu, digilen = %d\n", argpart->width, argpart->precision, digilen);
// 		// printf("max = %d\n", MAX(argpart->precision, digilen));
// 		// printf("nps = %d, nve = %d, pve = %d, space = %d\n", nps, nve, pve, space);
//
//
// 		if (!nveflag)
// 			len = len + dup_put_char2(padding, ' ') + 1; //precision includes digilen
//
// 		if (nve)
// 			ft_putchar('-'); //must be placed before precision
// 		else if (pve)
// 			ft_putchar('+');
// 		else if (space) //space is ignored when pve is present
// 			ft_putchar(' ');
//
// 		len = dup_put_char2(argpart->precision - digilen, '0') + 1;
// 		if (nve)
// 			ft_putnbr(nb * -1);
// 		else
// 			ft_putnbr(nb);
//
// 		if (nveflag)
// 			len = len + dup_put_char2(padding, ' ') + 1;
// 		// printf("width %zu precision %zu digilen %zu\n", argpart->width, argpart->precision , digilen);
//
// 	return(len);
// }
