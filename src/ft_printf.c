#include "../ft_printf.h"

char *ft_search(const char *str, char*search)
{
	int pt;

	pt = 0;
	while (*search)
	{
		if (ft_strchr(str, *search))
		{
			return(ft_strchr(str, *search));
		}
		search++;
	}
	return(0);
}

void parse(conversion_table *argpart, const char *format)//use error int to check if valid
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(format);
	argpart->conversions = (char *)malloc(sizeof(char) * len + 1);

	while (*format && !ft_strchr(SPECI, *format))
	{
		argpart->conversions[i] = *format;
		format++;
		i++;
	}
	argpart->conversions[i] = *format;
	argpart->conversions[i + 1] = '\0';

	if (ft_strchr(SPECI, *format))
		argpart->specifier = *format; //else can check valid specifier
}

int valid_conversion(conversion_table argpart, const char *format)
{
// if (argpart.error)
// 	return(0);
if (!ft_search(argpart.conversions, SPECI))
	return(0);
// else if (incompatable_conversions)
// 	return(0);
return(1);
}

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
	conversion_table argpart;
	va_start(list, format);

	va_end(list);
	while(*format)
	{
		if(*format == '%')
		{
			format++;
			parse(&argpart, format);
			if (valid_conversion(argpart, format))
			{
				ft_putstr("convers = |");
				ft_putstr(argpart.conversions);
				ft_putchar('|');
				// convert(&argpart, format);
				// print();
				// initial_and_free_lists();
				format = ft_search(format, SPECI) ? ft_search(format, SPECI) + 1 : ft_strchr(format, '\n');
			}
		}
		else
			format = format + (ft_putbasic(format));
	}
}
