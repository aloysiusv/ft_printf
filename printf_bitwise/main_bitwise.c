#include <stdio.h>
#include "ft_printf.h"
#include "limits.h"

void	print_u(t_info *t, va_list ap)
{
	unsigned int	u;
	size_t			len;
	size_t			len_prec;

	u = va_arg(ap, unsigned int);
	len = ft_ulllen_base(u, 10);
	len_prec = len;
	if ((t->flags & DOT) && t->prec > len_prec)
		len_prec = t->prec;
	if (t->flags & DASH)
	{
		while (len_prec > len++) 
			t->nbytes += write(1, "0", 1);
		ull_putnbrbase(t, u, "0123456789", 10);
	}
	while (t->width-- > len_prec)
	{
		if (t->flags & ZERO_PAD)
			t->nbytes += write(1, "0", 1);
		else
			t->nbytes += write(1, " ", 1);
	}
	if (!(t->flags & DASH))
	{
		while (len_prec > len++)
			t->nbytes += write(1, "0", 1);
		ull_putnbrbase(t, u, "0123456789", 10);
	}
}
// void	print_di(t_info *t, va_list ap)
// {
// 	int		di;
// 	size_t	len;
// 	di = va_arg(ap, int);
// 	len = ft_intlen_base(di, 10);
// 	if ((t->flags & PLUS) && di >= 0)
// 		len += 1;
// 	if ((t->flags & SPACE) && t->width <= len && di >= 0)
// 		t->nbytes += write(1, " ", 1);
// 	if ((t->flags & PLUS) && (t->flags & ZERO_PAD) && di >= 0)
// 		t->nbytes += write(1, "+", 1);
// 	if ((t->flags & ZERO_PAD) && di < 0)
// 		t->nbytes += write(1, "-", 1);
// 	if (t->flags & DASH)
// 	{
// 		if (di < 0)
// 			t->nbytes += write(1, "-", 1);
// 		long_putnbrbase(t, di, "0123456789", 10);
// 	}
// 	while (t->width-- > len)
// 	{
// 		if (t->flags & ZERO_PAD)
// 			t->nbytes += write(1, "0", 1);
// 		else
// 			t->nbytes += write(1, " ", 1);
// 	}
// 	if ((t->flags & PLUS) && !(t->flags & ZERO_PAD) && di >= 0)
// 		t->nbytes += write(1, "+", 1);
// 	if (!(t->flags & DASH))
// 	{
// 		if (!(t->flags & ZERO_PAD) && di < 0)
// 			t->nbytes += write(1, "-", 1);
// 		long_putnbrbase(t, di, "0123456789", 10);
// 	}
// }

void	print_xX(t_info *t, va_list ap, char *hash, char *base)
{
	unsigned int 	x;
	size_t			len;
	size_t			len_prec;
	x = va_arg(ap, unsigned int);
	len = ft_ulllen_base(x, 16);
	len_prec = len;
	if ((t->flags & DOT) && t->prec > len)
		len_prec = t->prec;
	if  ((t->flags & HASH) && x != 0)
	{
		t->nbytes += write(1, hash, 2);
		// len_prec = len_prec + 2;
	}
	if (t->flags & DASH)
	{
		while (len_prec > len++)
			t->nbytes += write(1, "0", 1);
		ull_putnbrbase(t, x, base, 16);
	}
	while (t->width-- > len_prec)
	{
		if ((t->flags & ZERO_PAD))
			t->nbytes += write(1, "0", 1); 
		else
			t->nbytes += write(1, " ", 1);
	}
	if (!(t->flags & DASH))
	{
		while (len_prec > len++)
			t->nbytes += write(1, "0", 1);
		ull_putnbrbase(t, x, base, 16);
	}
}

// int	main()
// {
// 	char	*str	= "plop";
// 	char	*str0 	= NULL;
// 	char	*str1	= "atchoum";
// 	char	c		= 'K';

// printf("");
// ft_printf("");
// printf("RET REAL[%d]\n", printf("Real: Hello World!\n"));
// printf("RET MINE[%d]\n", ft_printf("Mine: Hello World!\n"));
// printf("RET REAL[%d]\n", printf("Real: %c\n", 'Z'));
// printf("RET MINE[%d]\n", ft_printf("Mine: %c\n", 'Z'));
// printf("RET REAL[%d]\n", printf("Real: %c, %s\n", 'A', "hoy"));
// printf("RET MINE[%d]\n", ft_printf("Mine: %c, %s\n", 'A', "hoy"));
// printf("RET REAL[%d]\n", printf("Real: STR = %s\nReal: PTR = %p\n", str, str));
// printf("RET MINE[%d]\n", ft_printf("Mine: STR = %s\nMine: PTR = %p\n", str, str));
// printf("RET REAL[%d]\n", printf("Real: %d, %i\n", INT_MIN, 2147483647));
// printf("RET MINE[%d]\n", ft_printf("Mine: %d, %i\n", INT_MIN, 2147483647));
// printf("RET REAL[%d]\n", printf("Real: %u, %u, %u\n", 0, 346983, 2147483647));
// printf("RET MINE[%d]\n", ft_printf("Mine: %u, %u, %u\n", 0, 346983, 2147483647));
// printf("RET REAL[%d]\n", printf("Real: %x, %X, %x\n", 0, 346983, 2147483647));
// printf("RET MINE[%d]\n", ft_printf("Mine: %x, %X, %x\n", 0, 346983, 2147483647));
// printf("RET REAL[%d]\n", printf("Real: %%, %%\n"));
// printf("RET MINE[%d]\n", ft_printf("Mine: %%, %%\n"));

// printf("***BASIC TESTS TRIPOUILLE***\n");

// printf("RET REAL[%d]\n", printf("Real [%c]\n", '0'));
// printf("RET MINE[%d]\n", ft_printf("Mine [%c]\n", '0'));
// printf("RET REAL[%d]\n", printf("Real [ %c ]\n", '0'));
// printf("RET MINE[%d]\n", ft_printf("Mine [ %c ]\n", '0'));
// printf("RET REAL[%d]\n", printf("Real [ %c]\n", '0' - 256));
// printf("RET MINE[%d]\n", ft_printf("Mine [ %c]\n", '0' - 256));
// printf("RET REAL[%d]\n", printf("Real [%c ]\n", '0' + 256));
// printf("RET MINE[%d]\n", ft_printf("Mine [%c ]\n", '0' + 256));
// printf("RET REAL[%d]\n", printf("Real [%c %c %c] \n", '0', 0, '1'));
// printf("RET MINE[%d]\n", ft_printf("Mine [%c %c %c] \n", '0', 0, '1'));
// printf("RET REAL[%d]\n", printf("Real [%c %c %c] \n", ' ', ' ', ' '));
// printf("RET MINE[%d]\n", ft_printf("Mine [%c %c %c] \n", ' ', ' ', ' '));
// printf("RET REAL[%d]\n", printf("Real [%c %c %c] \n", '1', '2', '3'));
// printf("RET MINE[%d]\n", ft_printf("Mine [%c %c %c] \n", '1', '2', '3'));
// printf("RET REAL[%d]\n", printf("Real [%c %c %c] \n", '2', '1', 0));
// printf("RET MINE[%d]\n", ft_printf("Mine [%c %c %c] \n", '2', '1', 0));
// printf("RET REAL[%d]\n", printf("Real [%c %c %c] \n", 0, '1', '2'));
// printf("RET MINE[%d]\n", ft_printf("Mine [%c %c %c] \n", 0, '1', '2'));

// printf("***STRINGS***\n");

// printf("RET REAL[%d]\n", printf("Real [%s]\n", ""));
// printf("RET MINE[%d]\n", ft_printf("Mine [%s]\n", ""));
// printf("RET REAL[%d]\n", printf("Real [ %s]\n", ""));
// printf("RET MINE[%d]\n", ft_printf("Mine [ %s]\n", ""));
// printf("RET REAL[%d]\n", printf("Real [%s ]\n", ""));
// printf("RET MINE[%d]\n", ft_printf("Mine [%s ]\n", ""));
// printf("RET REAL[%d]\n", printf("Real [ %s ]\n", ""));
// printf("RET MINE[%d]\n", ft_printf("Mine [ %s ]\n", ""));
// printf("RET REAL[%d]\n", printf("Real [ %s ]\n", "-"));
// printf("RET MINE[%d]\n", ft_printf("Mine [ %s ]\n", "-"));
// printf("RET REAL[%d]\n", printf("Real [ %s %s ]\n", "", "-"));
// printf("RET MINE[%d]\n", ft_printf("Mine [ %s %s ]\n", "", "-"));
// printf("RET REAL[%d]\n", printf("Real [ %s %s ]\n", " - ", ""));
// printf("RET MINE[%d]\n", ft_printf("Mine [ %s %s ]\n", " - ", ""));
// printf("RET REAL[%d]\n", printf("Real [ %s %s %s %s ]\n", " - ", "", "4", ""));
// printf("RET MINE[%d]\n", ft_printf("Mine [ %s %s %s %s ]\n", " - ", "", "4", ""));
// printf("RET REAL[%d]\n", printf("Real [ %s %s %s %s %s ]\n", " - ", "", "4", "", "2 "));
// printf("RET MINE[%d]\n", ft_printf("Mine [ %s %s %s %s %s ]\n", " - ", "", "4", "", "2 "));

// printf("***BONUS***\n");

// printf("***DASH/WIDTH TEST***\n");
// printf("RET= [%d]\n", printf("Real:	[%-10c]\n", c));
// printf("RET= [%d]\n", ft_printf("Mine:	[%-10c]\n", c));
// printf("RET= [%d]\n", printf("Real:	[%-10s]\n", str1));
// printf("RET= [%d]\n", ft_printf("Mine:	[%-10s]\n", str1));
// printf("RET= [%d]\n", printf("Real:	STR = [%20s]\nReal:	PTR = [%20p]\n", str0, str0));
// printf("RET= [%d]\n", ft_printf("Mine:	STR = [%20s]\nMine:	PTR = [%20p]\n", str0, str0));
// printf("RET= [%d]\n", printf("Real:	STR = [%-20s]\nReal:	PTR = [%-20p]\n", str1, str1));
// printf("RET= [%d]\n", ft_printf("Mine:	STR = [%-20s]\nMine:	PTR = [%-20p]\n", str1, str1));
// printf("RET= [%d]\n", printf("Real:	[%-20d], [%20i]\n", INT_MIN, INT_MAX));
// printf("RET= [%d]\n", ft_printf("Mine:	[%-20d], [%20i]\n", INT_MIN, INT_MAX));
// printf("RET= [%d]\n", printf("Real:	[%-20d], [%20i]\n", 578, 578));
// printf("RET= [%d]\n", ft_printf("Mine:	[%-20d], [%20i]\n", 578, 578));
// printf("RET= [%d]\n", printf("Real:	[%10u], [%-10u], [%-20u]\n", 0, 346983, INT_MAX));
// printf("RET= [%d]\n", ft_printf("Mine:	[%10u], [%-10u], [%-20u]\n", 0, 346983, INT_MAX));
// printf("RET= [%d]\n", printf("Real:	[%x], [%10X], [%-20x]\n", 0, 346983, INT_MAX));
// printf("RET= [%d]\n", ft_printf("Mine:	[%x], [%10X], [%-20x]\n", 0, 346983, INT_MAX));
// printf("RET= [%d]\n", printf("Real:	[%%], [%%]\n"));
// printf("RET= [%d]\n", ft_printf("Mine:	[%%], [%%]\n"));

// printf("RET= [%d]\n", printf("Real: [%-10c]\n", c));
// printf("RET= [%d]\n", ft_printf("Mine: [%-c]\n", c));
// printf("RET= [%d]\n", printf("Real: [%5p]\n", &c));
// printf("RET= [%d]\n", ft_printf("Mine: [%5p]\n", &c));
// printf("RET= [%d]\n", printf("Real: [%05d]\n", 123));
// printf("RET= [%d]\n", ft_printf("Mine: [%05d]\n", 123));
// printf("RET= [%d]\n", printf("Real: [%05d]\n", -50));
// printf("RET= [%d]\n", ft_printf("Mine: [%05d]\n", -50));
// printf("RET= [%d]\n", printf("Real: [%+05d]\n", 4));
// printf("RET= [%d]\n", ft_printf("Mine: [%+05d]\n", 4));
// printf("RET= [%d]\n", printf("Real: [%-+5d]\n", -42));
// printf("RET= [%d]\n", ft_printf("Mine: [%-+5d]\n", -42));
// printf("RET= [%d]\n", printf("v UNSIGNED v\n"));
// printf("RET= [%d]\n", printf("Real: [%8u]\n", 997));
// printf("RET= [%d]\n", ft_printf("Mine: [%8u]\n", 997));
// printf("RET= [%d]\n", printf("Real: [%-8u]\n", 0));
// printf("RET= [%d]\n", ft_printf("Mine: [%-8u]\n", 0));
// printf("RET= [%d]\n", printf("Real: [%08u]\n", 997));
// printf("RET= [%d]\n", ft_printf("Mine: [%08u]\n", 997));
// printf("RET= [%d]\n", printf("v HEXA v\n"));
// printf("RET= [%d]\n", printf("Real: [%-10x]\n", 56));
// printf("RET= [%d]\n", ft_printf("Mine: [%-10x]\n", 56));
// printf("RET= [%d]\n", printf("Real: [%10X]\n", 22));
// printf("RET= [%d]\n", ft_printf("Mine: [%10X]\n", 22));
// printf("RET= [%d]\n", printf("Real: [%010X]\n", 76));
// printf("RET= [%d]\n", ft_printf("Mine: [%010X]\n", 76));
// printf("RET= [%d]\n", printf("Real: [%0#10x]\n", 34));
// printf("RET= [%d]\n", ft_printf("Mine: [%0#10x]\n", 34));
// printf("RET= [%d]\n", printf("Real: [%0#10x]\n", 0));
// printf("RET= [%d]\n", ft_printf("Mine: [%0#10x]\n", 0));
// printf("RET= [%d]\n", printf("Real: [%0#2x]\n", 88));
// printf("RET= [%d]\n", ft_printf("Mine: [%0#2x]\n", 88));
// printf("RET= [%d]\n", printf("Real: [%%]\n"));
// printf("RET= [%d]\n", ft_printf("Mine: [%%]\n"));
// printf("v PRECISION v\n");
// printf("RET= [%d]\n", printf("	CHARS	\n"));
// printf("RET= [%d]\n", printf("Real: 		[%5.3s]\n", "Hello"));
// printf("RET= [%d]\n", ft_printf("Mine: 		[%5.3s]\n", "Hello"));
// printf("RET= [%d]\n", printf("Real: 		[%2.4s]\n", "Hello"));
// printf("RET= [%d]\n", ft_printf("Mine: 		[%2.4s]\n", "Hello"));
// printf("RET= [%d]\n", printf("Real: 		[%5.0s]\n", "Hello"));
// printf("RET= [%d]\n", ft_printf("Mine: 		[%5.0s]\n", "Hello"));
// printf("	INTEGERS	\n");
// printf("RET= [%d]\n", printf("Real:		[%d]\n", 4224));
// printf("RET= [%d]\n", printf("Real:		[%+.d]\n", 4224));
// printf("RET= [%d]\n", printf("Real:		[%+.d]\n", -4224));
// printf("RET= [%d]\n", printf("Real: 		[%+.5d]\n", 4224));

// return (0);
// }

#include <stdio.h>
#include "limits.h"

// int	main()
// {
// 	char	*str 	= NULL;

// 	printf("");
// 	ft_printf("");
// 	printf("Real: Hello World!\n");
// 	ft_printf("Mine: Hello World!\n");
// 	printf("Real: [%c]\n", 'Z');
// 	ft_printf("Mine: [%c]\n", 'Z');
// 	printf("Real: [%c], [%-10s]\n", 'A', "hoy");
// 	ft_printf("Real: [%c], [%-10s]\n", 'A', "hoy");
// 	printf("Real: STR = [%s]\nReal: PTR = [%p]\n", str, str);
// 	ft_printf("Mine: STR = [%s]\nMine: PTR = [%p]\n", str, str);
// 	printf("Real: [%d], [%i]\n", INT_MIN, 2147483648);
// 	ft_printf("Mine: [%d], [%i]\n", INT_MIN, 2147483648);
// 	printf("Real: [%u], [%u], [%u]\n", 0, 346983, 2147483648);
// 	ft_printf("Mine: [%u], [%u], [%u]\n", 0, 346983, 2147483648);
// 	printf("Real: [%x], [%X], [%x]\n", 0, 346983, 2147483648);
// 	ft_printf("Mine: [%x], [%X], [%x]\n", 0, 346983, 2147483648);
// 	printf("Real: [%%], [%%]\n");
// 	ft_printf("Mine: [%%], [%%]\n");
// 	printf("v NOW FOR BONUSES v\n");
// 	printf("Real: [%-10c]\n", 'K');
// 	ft_printf("Mine: [%-10c]\n", 'K');
// 	printf("Real: [%010d]\n", -42);
// 	ft_printf("Mine: [%010d]\n", 42);
// 	printf("Real: [%-10d]\n", -42);
// 	printf("Mine: [%-10d]\n", 42);

// 	return (0);
// }

int main(void)
{
	// printf("***DASH TRIPOUILLE***\n");
	// printf("RET REAL: [%d]\n", printf(" %-2d ", -1));
	// printf("RET MINE: [%d]\n", ft_printf(" %-2d ", -1));
	// printf("RET REAL: [%d]\n", printf(" %-2d ", 1));
	// printf("RET MINE: [%d]\n", ft_printf(" %-2d ", 1));
	// printf("RET REAL: [%d]\n", printf(" %-2d ", 15));
	// printf("RET MINE: [%d]\n", ft_printf(" %-2d ", 15));
	// printf("RET REAL: [%d]\n", printf(" %-3d ", 16));
	// printf("RET MINE: [%d]\n", ft_printf(" %-3d ", 16));
	// printf("RET REAL: [%d]\n", printf(" %-4d ", 17));
	// printf("RET MINE: [%d]\n", ft_printf(" %-4d ", 17));
	// printf("RET REAL: [%d]\n", printf(" %-11d %-12d ", INT_MIN, INT_MAX));
	// printf("RET MINE: [%d]\n", ft_printf(" %-11d %-12d ", INT_MIN, INT_MAX));
	// printf("RET REAL: [%d]\n", printf(" %-1d %-2d ", 0, 0));
	// printf("RET MINE: [%d]\n", ft_printf(" %-1d %-2d ", 0, 0));
	// printf("REAL [% 3d]\n", INT_MIN);
	// ft_printf("MINE [% 3d]\n", INT_MIN);
	// printf("%d\n", printf("REAL [%04d]\n", -14));
	// printf("%d\n", ft_printf("MINE [%04d]\n", -14));
	// printf("%d\n", printf("REAL [%05d]\n", -15));
	// printf("%d\n", ft_printf("MINE [%05d]\n", -15));
	// printf("%d\n", printf("REAL [%06d]\n", -16));
	// printf("%d\n", ft_printf("MINE [%06d]\n", -16));
	// printf("%d\n", printf("REAL [%011d]\n", LONG_MAX));
	// printf("%d\n", ft_printf("MINE [%011d]\n", LONG_MAX));
	// printf("%d\n", printf("REAL [%012d]\n", LONG_MIN));
	// printf("%d\n", ft_printf("MINE [%012d]\n", LONG_MIN));
	// printf("%d\n", printf("REAL [%013d]\n", UINT_MAX));
	// printf("%d\n", ft_printf("MINE [%013d]\n", UINT_MAX));
	// printf("%d\n", printf("REAL [%014d]\n", ULONG_MAX));
	// printf("%d\n", ft_printf("MINE [%014d]\n", ULONG_MAX));
	// printf("%d\n", printf("REAL [%015d]\n", 9223372036854775807LL));
	// printf("%d\n", ft_printf("MINE [%015d]\n", 9223372036854775807LL));
	// printf("%d\n", printf("REAL [%09d %010d %011d %012d %013d %014d %015d]\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	// printf("%d\n", ft_printf("MINE [%09d %010d %011d %012d %013d %014d %015d]\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));

	// printf("***HASH + PREC***\n");

	// printf("REAL RET = [%d]\n", printf("REAL: [%.3i]\n", 118));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.3i]\n", 118));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.4i]\n", 148));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.4i]\n", 148));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.1i]\n", 158));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.1i]\n", 158));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.2i]\n", 168));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.2i]\n", 168));
	// printf("*************************");

	// printf("REAL RET = [%d]\n", printf("REAL: [%.1u]\n", 0));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.1u]\n", 0));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.2u]\n", -1));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.2u]\n", -1));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.2u]\n", 1));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.2u]\n", 1));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.1u]\n", 9));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.1u]\n", 9));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.2u]\n", 10));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.2u]\n", 10));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.3u]\n", 11));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.3u]\n", 11));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.4u]\n", 15));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.4u]\n", 15));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.5u]\n", 16));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.5u]\n", 16));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.6u]\n", 17));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.6u]\n", 17));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.1u]\n", 99));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.1u]\n", 99));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.2u]\n", 100));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.2u]\n", 100));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.3u]\n", 101));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.3u]\n", 101));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.1u]\n", -9));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.1u]\n", -9));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.2u]\n", -10));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.2u]\n", -10));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.3u]\n", -11));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.3u]\n", -11));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.4u]\n", -14));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.4u]\n", -14));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.1u]\n", -15));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.1u]\n", -15));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.2u]\n", -16));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.2u]\n", -16));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.3u]\n", -99));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.3u]\n", -99));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.3u]\n", -100));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.3u]\n", -100));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.4u]\n", -101));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.4u]\n", -101));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.8u]\n", INT_MAX));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.8u]\n", INT_MAX));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.9u]\n", INT_MIN));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.9u]\n", INT_MIN));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.10u]\n", LONG_MAX));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.10u]\n", LONG_MAX));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.11u]\n", LONG_MIN));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.11u]\n", LONG_MIN));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.12u]\n", UINT_MAX));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.12u]\n", UINT_MAX));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.13u]\n", ULONG_MAX));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.13u]\n", ULONG_MAX));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.14u]\n", 9223372036854775807LL));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.14u]\n", 9223372036854775807LL));
	// printf("REAL RET = [%d]\n", printf("REAL: [%.8u %.9u %.10u %.11u %.12u %.13u %.14u]\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	// printf("MINE RET = [%d]\n", ft_printf("MINE: [%.8u %.9u %.10u %.11u %.12u %.13u %.14u]\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42)); 
	
	printf("REAL RET = [%d]\n", printf("[ %-1u ]", 0));
	printf("MINE RET = [%d]\n", ft_printf("[ %-1u ]", 0));
	printf("REAL RET = [%d]\n", printf("[ %-2u ]", -1));
	printf("MINE RET = [%d]\n", ft_printf("[ %-2u ]", -1));
	printf("REAL RET = [%d]\n", printf("[ %-3u ]", 1));
	printf("MINE RET = [%d]\n", ft_printf("[ %-3u ]", 1));
	printf("REAL RET = [%d]\n", printf("[ %-4u ]", 9));
	printf("MINE RET = [%d]\n", ft_printf("[ %-4u ]", 9));
	printf("REAL RET = [%d]\n", printf(" %-1u ", 10));
	printf("MINE RET = [%d]\n", ft_printf(" %-1u ", 10));
	printf("REAL RET = [%d]\n", printf(" %-2u ", 11));
	printf("MINE RET = [%d]\n", ft_printf(" %-2u ", 11));
	printf("REAL RET = [%d]\n", printf(" %-3u ", 15));
	printf("MINE RET = [%d]\n", ft_printf(" %-3u ", 15));
	printf("REAL RET = [%d]\n", printf(" %-4u ", 16));
	printf("MINE RET = [%d]\n", ft_printf(" %-4u ", 16));
	printf("REAL RET = [%d]\n", printf(" %-5u ", 17));
	printf("MINE RET = [%d]\n", ft_printf(" %-5u ", 17));
	printf("REAL RET = [%d]\n", printf(" %-1u ", 99));
	printf("MINE RET = [%d]\n", ft_printf(" %-1u ", 99));
	printf("REAL RET = [%d]\n", printf(" %-2u ", 100));
	printf("MINE RET = [%d]\n", ft_printf(" %-2u ", 100));
	printf("REAL RET = [%d]\n", printf(" %-3u ", 101));
	printf("MINE RET = [%d]\n", ft_printf(" %-3u ", 101));
	printf("REAL RET = [%d]\n", printf(" %-1u ", -9));
	printf("MINE RET = [%d]\n", ft_printf(" %-1u ", -9));
	printf("REAL RET = [%d]\n", printf(" %-2u ", -10));
	printf("MINE RET = [%d]\n", ft_printf(" %-2u ", -10));
	printf("REAL RET = [%d]\n", printf(" %-3u ", -11));
	printf("MINE RET = [%d]\n", ft_printf(" %-3u ", -11));
	printf("REAL RET = [%d]\n", printf(" %-4u ", -14));
	printf("MINE RET = [%d]\n", ft_printf(" %-4u ", -14));
	printf("REAL RET = [%d]\n", printf(" %-5u ", -15));
	printf("MINE RET = [%d]\n", ft_printf(" %-5u ", -15));
	printf("REAL RET = [%d]\n", printf(" %-6u ", -16));
	printf("MINE RET = [%d]\n", ft_printf(" %-6u ", -16));
	printf("REAL RET = [%d]\n", printf(" %-1u ", -99));
	printf("MINE RET = [%d]\n", ft_printf(" %-1u ", -99));
	printf("REAL RET = [%d]\n", printf(" %-2u ", -100));
	printf("MINE RET = [%d]\n", ft_printf(" %-2u ", -100));
	printf("REAL RET = [%d]\n", printf(" %-3u ", -101));
	printf("MINE RET = [%d]\n", ft_printf(" %-3u ", -101));
	printf("REAL RET = [%d]\n", printf(" %-9u ", INT_MAX));
	printf("MINE RET = [%d]\n", ft_printf(" %-9u ", INT_MAX));
	printf("REAL RET = [%d]\n", printf(" %-10u ", INT_MIN));
	printf("MINE RET = [%d]\n", ft_printf(" %-10u ", INT_MIN));
	printf("REAL RET = [%d]\n", printf(" %-11u ", LONG_MAX));
	printf("MINE RET = [%d]\n", ft_printf(" %-11u ", LONG_MAX));
	printf("REAL RET = [%d]\n", printf(" %-12u ", LONG_MIN));
	printf("MINE RET = [%d]\n", ft_printf(" %-12u ", LONG_MIN));
	printf("REAL RET = [%d]\n", printf(" %-13u ", UINT_MAX));
	printf("MINE RET = [%d]\n", ft_printf(" %-13u ", UINT_MAX));
	printf("REAL RET = [%d]\n", printf(" %-14u ", ULONG_MAX));
	printf("MINE RET = [%d]\n", ft_printf(" %-14u ", ULONG_MAX));
	printf("REAL RET = [%d]\n", printf(" %-9u %-10u %-11u %-12u %-13u %-14u %-15u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	printf("MINE RET = [%d]\n", ft_printf(" %-9u %-10u %-11u %-12u %-13u %-14u %-15u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	printf("REAL RET = [%d]\n", printf(" %-9u %-10u %-11u %-12u %-13u %-14u %-15u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	printf("MINE RET = [%d]\n", ft_printf(" %-9u %-10u %-11u %-12u %-13u %-14u %-15u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	return (0);
}