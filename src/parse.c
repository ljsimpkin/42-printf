#include "../ft_printf.h"

// printf(%[FLAGS][WIDTH][.PRECISION][LENGTH][SPECIFIER])

void parse_conversions(conversion_table *argpart, const char *format)
{
	int i;

	i = 0;
	argpart->conlen = ft_strlen(format);
	argpart->conversions = (char *)malloc(sizeof(char) * argpart->conlen + 1);
	ft_bzero(argpart->conversions, argpart->conlen);

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
	argpart->flags = ft_strnew(argpart->conlen + 1);
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
// void parse_width(conversion_table *argpart, const char *format);
// void parse_precision(conversion_table *argpart, const char *format);
// void parse_length(conversion_table *argpart, const char *format);
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

int parse(conversion_table *argpart, const char *format)//use error int to check if valid
{
	parse_conversions(argpart, format);
	parse_flags(argpart, format);
	argpart->width = ft_atoi_skip(format);//parse_width(argpart, format);
	if (ft_strchr(format, '.'))
		argpart->precision = ft_atoi_skip(ft_strchr(format, '.'));
	// void parse_precision(conversion_table *argpart, const char *format);
	// void parse_length(conversion_table *argpart, const char *format);
	parse_specifiers(argpart, format);
	// printf("Width = |%zu|\n", argpart->width);
	// printf("Precision = |%zu|\n", argpart->precision);

	// printf("atoi = %zu\n", argpart->width);
	return(ft_strlen(argpart->conversions));
}
