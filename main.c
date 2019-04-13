#include "ft_printf.h"

int main()
{
	char *str  = "a";
	char c = 'a';
	// ft_printf("str = |%s",str);
	ft_printf("str = |%-+5d|\n", 50);

	return(0);
}
