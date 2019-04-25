#include "includes/ft_printf.h"
#include "libft/libft.h"

int main()
{
	char *str  = "a";
	long int nb = 123456789123456789;
	//printf("prif |%d| after\n", printf("hello %p ", str));
	//ft_printf("prif |%d| after\n", ft_printf("hello %p ", str));  //#works over and withinn precision
	printf("prif |%5%| after\n"); //#works over and withinn precision
	ft_printf("test |%5%| after\n");

	return(0);
}
