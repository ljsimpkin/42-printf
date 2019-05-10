#include "ft_printf.h"

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

long long int handle_length(va_list list, cv_table *argpart)
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

int call_handler(va_list list, cv_table *argpart)
{
	int (*func[12])(va_list, cv_table*);
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