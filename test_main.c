#include "includes/ft_printf.h"
#include "libft/libft.h"
#include <limits.h>


int main()
{

	ft_printf("%lu\n", LONG_MAX);
	printf("%lu\n", LONG_MAX);
	ft_printf("%lu\n", ((long) INT_MAX) + 1);
	printf("%lu\n", ((long) INT_MAX) + 1);
	ft_printf("%u\n", INT_MAX);
	printf("%u\n", INT_MAX);
	ft_printf("%u\n", 1234567890);
	printf("%u\n", 1234567890);
	ft_printf("%u\n", 42);
	printf("%u\n", 42);
	ft_printf("%u\n", 1);
	printf("%u\n", 1);
	ft_printf("%u\n", 0);
	printf("%u\n", 0);
	ft_printf("%u\n", -1);
	printf("%u\n", -1);
	ft_printf("%u\n", -52543054);
	printf("%u\n", -52543054);
	ft_printf("%u\n", INT_MIN);
	printf("%u\n", INT_MIN);
	ft_printf("%lu\n", ((long) INT_MIN) - 1);
	printf("%lu\n", ((long) INT_MIN) - 1);
	ft_printf("%lu\n", LONG_MIN);
	printf("%lu\n", LONG_MIN);

	ft_printf("%x\n", 0);
printf("%x\n", 0);
ft_printf("%x\n", 1);
printf("%x\n", 1);
ft_printf("%x\n", 66);
printf("%x\n", 66);
ft_printf("%x\n", 43981);
printf("%x\n", 43981);
ft_printf("%x\n", INT_MAX);
printf("%x\n", INT_MAX);
ft_printf("%lx\n", (long) INT_MAX + 1);
printf("%lx\n", (long) INT_MAX + 1);
ft_printf("%lx\n", LONG_MAX);
printf("%lx\n", LONG_MAX);
ft_printf("%lx\n", ULONG_MAX);
printf("%lx\n", ULONG_MAX);
ft_printf("%x\n", -1);
printf("%x\n", -1);
ft_printf("%x\n", -230538686);
printf("%x\n", -230538686);
ft_printf("%x\n", INT_MIN);
printf("%x\n", INT_MIN);
ft_printf("%lx\n", LONG_MIN);
printf("%lx\n", LONG_MIN);

ft_printf("%s\n", "Hello world.");
printf("%s\n", "Hello world.");
ft_printf("%.s\n", "Hello world.");
printf("%.s\n", "Hello world.");
ft_printf("%.0s\n", "Hello world.");
printf("%.0s\n", "Hello world.");
ft_printf("%.4s\n", "Hello world.");
printf("%.4s\n", "Hello world.");

ft_printf("%.0d\n", 42);
printf("%.0d\n", 42);
ft_printf("%.1d\n", 42);
printf("%.1d\n", 42);
ft_printf("%.2d\n", 42);
printf("%.2d\n", 42);
ft_printf("%.3d\n", 42);
printf("%.3d\n", 42);
ft_printf("%.10d\n", 42);
printf("%.10d\n", 42);

ft_printf("%.0d\n", -42);
printf("%.0d\n", -42);
ft_printf("%.1d\n", -42);
printf("%.1d\n", -42);
ft_printf("%.2d\n", -42);
printf("%.2d\n", -42);
ft_printf("%.3d\n", -42);
printf("%.3d\n", -42);
ft_printf("%.10d\n", -42);
printf("%.10d\n", -42);

ft_printf("%.0i\n", 42);
printf("%.0i\n", 42);
ft_printf("%.2i\n", 42);
printf("%.2i\n", 42);
ft_printf("%.4i\n", 42);
printf("%.4i\n", 42);

ft_printf("%.0o\n", 34);
printf("%.0o\n", 34);
ft_printf("%.2o\n", 34);
printf("%.2o\n", 34);
ft_printf("%.4o\n", 34);
printf("%.4o\n", 34);
ft_printf("%#.4o\n", 34);
printf("%#.4o\n", 34);
ft_printf("%#.3o\n", 34);
printf("%#.3o\n", 34);
ft_printf("%#.2o\n", 34);
printf("%#.2o\n", 34);

ft_printf("%.0u\n", 42);
printf("%.0u\n", 42);
ft_printf("%.2u\n", 42);
printf("%.2u\n", 42);
ft_printf("%.4u\n", 42);
printf("%.4u\n", 42);

ft_printf("%.0x\n", 66);
printf("%.0x\n", 66);
ft_printf("%.2x\n", 66);
printf("%.2x\n", 66);
ft_printf("%.4x\n", 66);
printf("%.4x\n", 66);

ft_printf("%.0X\n", 66);
printf("%.0X\n", 66);
ft_printf("%.2X\n", 66);
printf("%.2X\n", 66);
ft_printf("%.4X\n", 66);
printf("%.4X\n", 66);

ft_printf("%#.1x\n", 66);
printf("%#.1x\n", 66);
ft_printf("%#.2X\n", 66);
printf("%#.2X\n", 66);
ft_printf("%#.3x\n", 66);
printf("%#.3x\n", 66);
ft_printf("%#.8X\n", 66);
printf("%#.8X\n", 66);

ft_printf("%#.f\n", 42.0);
printf("%#.f\n", 42.0);
ft_printf("%#.1F\n", 42.0);
printf("%#.1F\n", 42.0);
ft_printf("%#.3f\n", 42.0);
printf("%#.3f\n", 42.0);
ft_printf("%#.8F\n", 42.0);
printf("%#.8F\n", 42.0);

ft_printf("%lo\n", LONG_MAX);
printf("%lo\n", LONG_MAX);
ft_printf("%lo\n", ((long) INT_MAX) + 1);
printf("%lo\n", ((long) INT_MAX) + 1);
ft_printf("%o\n", INT_MAX);
printf("%o\n", INT_MAX);
ft_printf("%o\n", 16434824);
printf("%o\n", 16434824);
ft_printf("%o\n", 34);
printf("%o\n", 34);
ft_printf("%o\n", 1);
printf("%o\n", 1);
ft_printf("%o\n", 0);
printf("%o\n", 0);
ft_printf("%o\n", -1);
printf("%o\n", -1);
ft_printf("%o\n", -30);
printf("%o\n", -30);
ft_printf("%o\n", -1665406182);
printf("%o\n", -1665406182);
ft_printf("%o\n", INT_MIN);
printf("%o\n", INT_MIN);
ft_printf("%lo\n", ((long) INT_MIN) - 1);
printf("%lo\n", ((long) INT_MIN) - 1);
ft_printf("%lo\n", LONG_MIN);
printf("%lo\n", LONG_MIN);
	return(0);
}
