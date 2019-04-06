#include "../ft_printf.h"



int ft_putbasic(const char *format)
{
	char *percent_ptr = 0;
	int str_len = 0;
	percent_ptr = ft_strchr(format, '%');

	if (percent_ptr)
		str_len = percent_ptr - format;
	else
		str_len = ft_strlen(format);

	write(1,format, str_len);
	return(str_len);

}

void ft_printf(const char *format, ...)
{
	va_list list;
	va_start(list, format);

	va_end(list);
	while(*format)
	{
		if(*format == '%')
		{
		format++;
		// 	ft_parse(format);
		// 	error_check(format)
		// 	print
		}
		else
			format = format + (ft_putbasic(format));
	}
}

// char *s = va_arg(list, char *);
// int i = va_arg(list, int);
// int i2 = va_arg(list, int);
