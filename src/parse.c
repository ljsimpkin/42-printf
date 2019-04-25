#include "ft_printf.h"

// printf(%[FLAGS][WIDTH][.PRECISION][LENGTH][SPECIFIER])

void parse_conversions(conversion_table *argpart, const char *format)
{
	int i;

	i = 0;
	argpart->formatlen = ft_strlen(format);
	argpart->conversions = (char *)malloc(sizeof(char) * argpart->formatlen + 1);
	ft_bzero(argpart->conversions, argpart->formatlen);

	while (*format && !ft_strchr(SPECI, *format))
	{
		argpart->conversions[i] = *format;
		format++;
		i++;
	}
	argpart->conversions[i] = *format;
	argpart->conversions[i + 1] = '\0';
}

void parse_flags(conversion_table *argpart, const char *format)
{
	int i;
	int y;

	i = 0;
	y = 0;
	argpart->flags = ft_strnew(argpart->formatlen + 1);
	while (argpart->conversions[i])
	{
		if (ft_strchr(FLAGS, argpart->conversions[i]))
		{
			argpart->flags[y] = argpart->conversions[i];
			y++;
		}
		i++;
	}
	argpart->flags[i] = '\0';
}

void parse_specifiers(conversion_table *argpart, const char *format)
{
	char *specifer = (ft_search(SPECI, argpart->conversions));
	if (specifer)
		argpart->specifier = *specifer;
}

int parse_width(conversion_table *argpart, const char *format)
{
	argpart->width = ft_atoi_skip(format);
	return(1);
}

int parse_zeroflag(conversion_table *argpart, const char *format)
{
	int i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '0')
			return(1);
		else if (ft_strchr("123456789", format[i]))
			return(0);
		i++;
	}
	return(0);
}

int parse_lengths(conversion_table *argpart, const char *format)
{
	char * pt;

	pt = 0;
	if ((pt = ft_strchr(format, 'h')))
	{
		if (*(pt + 1) == 'h')
			argpart->lengths = 1;
		else
			argpart->lengths = 2;
	}
	else if (((pt = ft_strchr(format, 'l'))))
	{
		if (*(pt + 1) == 'l')
			argpart->lengths = 4;
		else
			argpart->lengths = 3;
	}
	else if (((pt = ft_strchr(format, 'L'))))
		argpart->lengths = 5;
	else
		argpart->lengths = 0;

	return(0);
}

int parse(conversion_table *argpart, const char *format)//use error int to check if valid
{
	parse_conversions(argpart, format);
	parse_flags(argpart, format);
	argpart->zero_flag = parse_zeroflag(argpart, format);
	argpart->width = ft_atoi_skip(format);//parse_width(argpart, format);
		// argpart->zero_flag = parse_zeroflag(argpart->width);
	if (ft_strchr(format, '.'))
		argpart->precision = ft_atoi_skip(ft_strchr(format, '.') + 1);

	parse_specifiers(argpart, format);
	parse_lengths(argpart, format);
	// printf("atoi = %zu\n", argpart->width);
	return(ft_strlen(argpart->conversions));
}
