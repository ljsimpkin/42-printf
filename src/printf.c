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

int valid_conversion(conversion_table argpart, const char *format)
{
// if (argpart.error)
// 	return(0);
if (!ft_search(argpart.conversions, SPECI))
{
	ft_putstr("invalid conversions");
	return(0);
}
// else if valid chars
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

void initalize(conversion_table *argpart)
{
	argpart->conversions = 0;
	argpart->specifier = 0;
	argpart->flags = 0;
	argpart->error = 0;
	argpart->conlen = 0;
	argpart->width = 0;
	argpart->precision = 0;
}

int ft_printf(const char *format, ...)
{
	int place;
	place = 0;
	va_list list;
	conversion_table argpart;
	initalize(&argpart);
	va_start(list, format);

	va_end(list);
	while(*format)
	{
		if(*format == '%')
		{
			format++;
			place = parse(&argpart, format);
			if (valid_conversion(argpart, format))
			{
				// convert(&argpart, format);
				call_handler(list, &argpart);
				// initial_and_free_lists();
				format = place + format; // format = ft_search(format, SPECI) ? ft_search(format, SPECI) + 1 : ft_strchr(format, '\n');
			}
		}
		else
			format = format + (ft_putbasic(format));
	}
	return(0);
}