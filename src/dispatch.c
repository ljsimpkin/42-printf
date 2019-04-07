#include "../ft_printf.h"

int search_specifiers(const char *format)
{
	char *speci;

	speci = "scd";
	if (ft_strchr(speci, *format))
        	return(1);
    return (0);
}


int search_flags(const char *format)
{
	char *flags;

	flags = "#0-+";
	if (ft_strchr(flags, *format))
        	return(1);
    return (0);
}

int search_length(const char *format)
{
	char *length;

	length = "hlL";
	if (ft_strchr(length, *format))
        	return(1);
    return (0);
}

/*
min number of chars to be printed. If the value to be printed is
shorter than this number, the reult is padded with blank spaces
*/
int search_width(const char *format)
{
	char *length;

	length = "1234567890";
	if (ft_strchr(length, *format))
        	return(1);
    return (0);
}

int search_precision(const char *format)
{
	char *length;

	length = ".";
	if (ft_strchr(length, *format))
        	return(1);
    return (0);
}

// void parse(t_table *argpart, const char *format)
// {
// 	while (*format && !(search_specifiers(format)))
// 	{
// 		if(search_flags(format))
// 			argpart->flag = ft_strjoin(format, argpart->flag);
// 		format++;
// 		// else if()
// 	}
// }
