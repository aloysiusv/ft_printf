#include <stdio.h>
#include <unistd.h>
#include "limits.h"
#include "ft_printf_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_ulllen_base(unsigned long long n, int base_len)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len = len + 1;
	while (n)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

size_t	ft_intlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

unsigned int	if_symbol(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

size_t	ft_atoui(const char *str)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res);
}

void	ull_putnbrbase(t_info *t, unsigned long long nb, char *str, size_t base)
{
	unsigned long long	lol;

	lol = nb;
	if (lol >= base)
		ull_putnbrbase(t, lol / base, str, base);
	NBYTES += write(1, &str[lol % base], 1);
}

void	long_putnbrbase(t_info *t, long nb, char *str, int base)
{
	long	lol;

	if (nb >= 0)
		lol = nb;
	else
		lol = -nb;
	if (lol >= base)
		long_putnbrbase(t, lol / base, str, base);
	NBYTES += write(1, &str[lol % base], 1);
}

void	store_flags(t_info *t, const char *str)
{
	if (str[POS] == ' ' && PLUS == FALSE)
		SPACE = TRUE;
	else if (str[POS] == '-')
	{
		DASH = TRUE;
		ZERO_PAD = FALSE;
	}
	else if (str[POS] == '0' && DASH == FALSE && DOT == FALSE)
		ZERO_PAD = TRUE;
	else if (str[POS] == '#')
		HASH = TRUE;
	else if (str[POS] == '+')
	{
		PLUS = TRUE;
		SPACE = FALSE;
	}
	POS++;
}

void	store_width(t_info *t, const char *str)
{
	char 	*width_ascii;
	size_t	len;
	size_t	j;
	size_t	k;

	len = 0;
	j = POS;
	while (if_symbol("cspdiuxX%", str[j]) == FALSE)
	{
		if (str[j] >= '0' && str[j] <= '9')
			len++;
		j++;
	}
	width_ascii = (char *)malloc(sizeof(char) * len + 1);
	if (width_ascii == NULL)
		return ;
	k = 0;
	while (str[POS] >= '0' && str[POS] <= '9')
		width_ascii[k++] = str[POS++];
	width_ascii[k] = '\0';
	WIDTH = ft_atoui((const char *)width_ascii);
	free(width_ascii);
}

void	store_precision(t_info *t, const char *str)
{
	char 	*precision_ascii;
	size_t	len;
	size_t	j;
	size_t	k;

	len = 0;
	j = POS;
	j++;
	while (if_symbol("cspdiuxX%", str[j]) == FALSE)
	{
		if (str[j] >= '0' && str[j] <= '9')
			len++;
		j++;
	}
	precision_ascii = (char *)malloc(sizeof(char) * len + 1);
	if (precision_ascii == NULL)
		return ;
	k = 0;
	POS++;
	while (str[POS] >= '0' && str[POS] <= '9')
		precision_ascii[k++] = str[POS++];
	precision_ascii[k] = '\0';
	PREC = ft_atoui((const char *)precision_ascii);
	free(precision_ascii);
}

void	print_c(t_info *t, va_list ap)
{
	char	c;
	
	c = '\0';
	c = (char)va_arg(ap, int);
	if (DASH == TRUE)
		NBYTES += write(1, &c, 1);
	if (WIDTH > 0)
		while (--WIDTH > 0)
			NBYTES += write(1, " ", 1);
	if (DASH == FALSE)
		NBYTES += write(1, &c, 1);
}

void	print_s(t_info *t, va_list ap)
{
	char	*s;
	size_t	i;
	size_t	len;

	i = 0;
	s = va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	if (DOT == FALSE)
	{
		len = 0;
		len = ft_strlen(s);
		if (DASH == TRUE)
			while (s[i])
				NBYTES += write(1, &s[i++], 1);
		if (WIDTH > len)
		{
			WIDTH = WIDTH - len;
			while (WIDTH > 0)
			{
				NBYTES += write(1, " ", 1);
				WIDTH--;
			}
		}
		if (DASH == FALSE)
			while (s[i])
				NBYTES += write(1, &s[i++], 1);
		}
		else if (DOT == TRUE)
		{
			while (WIDTH > PREC)
			{
				NBYTES += write(1, " ", 1);
				WIDTH--;
			}
			while (i < PREC)
				NBYTES += write(1, &s[i++], 1);
		}
}

void	print_p(t_info *t, va_list ap)
{
	unsigned long long	p;
	unsigned long long 	len;

	len = 0;
	p = va_arg(ap, unsigned long long);
	len = ft_ulllen_base(p, 10);
	if (!p)
		len = ft_strlen("(nil)");
	if (p && DASH == TRUE)
	{
		NBYTES += write(1, "0x", 2);
		ull_putnbrbase(t, p, "0123456789abcdef", 16);
	}
	if (!p && DASH == TRUE)
		NBYTES += write(1, "(nil)", 5);
	if (WIDTH > len)
	{
		WIDTH = WIDTH - len;
		while (WIDTH > 0)
		{
			NBYTES += write(1, " ", 1);
			WIDTH--;
		}
	}
	if (!p && DASH == FALSE)
		NBYTES += write(1, "(nil)", 5);
	if (p && DASH == FALSE)
	{
		NBYTES += write(1, "0x", 2);
		ull_putnbrbase(t, p, "0123456789abcdef", 16);
	}
}

void	print_di(t_info *t, va_list ap)
{
	int		di;
	size_t	len;

	len = 0;
	di = va_arg(ap, int);
	len = ft_intlen(di);
	if (di == 0)
		len = len + 1;
	if (PLUS == TRUE && di >= 0)
	{
		NBYTES += write(1, "+", 1);
		len = len + 1;
	}
	if (di < 0)
		NBYTES += write(1, "-", 1);
	if (SPACE == TRUE && WIDTH == 0)
		NBYTES += write(1, " ", 1);
	if (DASH == TRUE)
			long_putnbrbase(t, di, "0123456789", 10);
	if (WIDTH > len)
	{	
		WIDTH = WIDTH - len;
		while (WIDTH  > 0)
		{
			if (ZERO_PAD == TRUE)
				NBYTES += write(1, "0", 1); 
			else
				NBYTES += write(1, " ", 1);
			WIDTH--;
		}		
	}
	if (DASH == FALSE)
		long_putnbrbase(t, di, "0123456789", 10);
}

void	print_u(t_info *t, va_list ap)
{
	unsigned int	u;
	size_t			len;

	len = 0;
	u = va_arg(ap, unsigned int);
	len = ft_ulllen_base(u, 10);
	if (DASH == TRUE)
		ull_putnbrbase(t, u, "0123456789", 10);
	if (WIDTH > len)
	{
		WIDTH = WIDTH - len;
		while (WIDTH-- > 0)
		{
			if (ZERO_PAD == TRUE)
				NBYTES += write(1, "0", 1); 
			else
				NBYTES += write(1, " ", 1);
		}
	}
	if (DASH == FALSE)
		ull_putnbrbase(t, u, "0123456789", 10);
}

void	print_xX(t_info *t, va_list ap)
{
	unsigned int 	x;
	size_t			len;

	len = 0;
	x = va_arg(ap, unsigned int);
	len = ft_ulllen_base(x, 16);
	if  (HASH == TRUE && x != 0)
	{
		if (TYPE == 'x')
			NBYTES += write(1, "0x", 2);
		else
			NBYTES += write(1, "0X", 2);
		len = len + 2;
	}
	if (DASH == TRUE)
	{
		if (TYPE == 'x')
			ull_putnbrbase(t, x, "0123456789abcdef", 16);
		else
			ull_putnbrbase(t, x, "0123456789ABCDEF", 16);
	}
	if (WIDTH > len)
	{
		WIDTH = WIDTH - len;
		while (WIDTH > 0)
		{	
			if (ZERO_PAD == TRUE)
				NBYTES += write(1, "0", 1); 
			else
				NBYTES += write(1, " ", 1);
			WIDTH--;
		}
	}
	if (DASH == FALSE)
	{
		if (TYPE == 'x')
			ull_putnbrbase(t, x, "0123456789abcdef", 16);
		else
			ull_putnbrbase(t, x, "0123456789ABCDEF", 16);
	}
}

void	print_percent(t_info *t)
{
	NBYTES += write(1, "%", 1);
}

void	go_to_conversion(t_info *t, va_list ap)
{
	if (TYPE == 'c')
		print_c(t, ap);
	if (TYPE == 's')
		print_s(t, ap);
	if (TYPE == 'p')
		print_p(t, ap);
	if (TYPE == 'd' || TYPE == 'i')
		print_di(t, ap);
	if (TYPE == 'u')
		print_u(t, ap);
	if (TYPE == 'x' || TYPE == 'X')
		print_xX(t, ap);
	if (TYPE == '%')
		print_percent(t);
}

void	analyse_conversion(t_info *t, const char *str, va_list ap)
{
	POS++;
	while (if_symbol(" -0#+", str[POS]) == TRUE)
		store_flags(t, str);
	while (str[POS] >= '1' && str[POS] <= '9')
		store_width(t, str);
	if (str[POS] == '.') 
	{
		DOT = TRUE;
		ZERO_PAD = FALSE;
		if (str[POS + 1] == '0')
			PREC = 0;
		store_precision(t, str);
	}
	if (if_symbol("cspdiuxX%", str[POS]) == TRUE)
	{
		TYPE = str[POS];
		go_to_conversion(t, ap);
	}
}

void	reset_info(t_info *t)
{
	SPACE = FALSE;
	DASH = FALSE;
	ZERO_PAD = FALSE;
	DOT = FALSE;
	HASH = FALSE;
	PLUS = FALSE;
	TYPE = '\0';
	WIDTH = 0;
	PREC = 1;
}

void	init_info(t_info *t)
{
	SPACE = FALSE;
	DASH = FALSE;
	ZERO_PAD = FALSE;
	DOT = FALSE;
	HASH = FALSE;
	PLUS = FALSE;
	TYPE = '\0';
	WIDTH = 0;
	PREC = 1;
	NBYTES = 0;
	POS = 0;
}

size_t	do_your_magic(const char *str, t_info *t, va_list ap)
{
	init_info(t);
	while (str[POS])
	{
		if (str[POS] == '%')
		{
			reset_info(t);
			analyse_conversion(t, str, ap);
		}
		else
			NBYTES += write(1, &str[POS], 1);
		POS++;
	}
	return (NBYTES);
}

int ft_printf(const char *format, ...)
{
	va_list	ap;
	t_info	t[1];
	
	if (format == NULL)
		return (-1);
	va_start(ap, format);
	NBYTES = do_your_magic(format, t, ap);
	va_end(ap);

	return (NBYTES);
}

int	main(void)
{
	char c 		= 'K';
	char *str0	= NULL;
	char *str1	= "Atchoum";
	
	printf("***BASIC TESTS***\n");
	// printf("");
	// ft_printf("");
	printf("Real:	Hello World!\n");
	ft_printf("Mine:	Hello World!\n");
	printf("Real:	[%c]\n", c);
	ft_printf("Mine:	[%c]\n", c);
	printf("Real:	[%s]\n", str1);
	ft_printf("Mine:	[%s]\n", str1);
	printf("Real:	STR = [%s]\nReal:	PTR = [%p]\n", str0, str0);
	ft_printf("Mine:	STR = [%s]\nMine:	PTR = [%p]\n", str0, str0);
	printf("Real:	[%d], [%i]\n", INT_MIN, INT_MAX);
	ft_printf("Mine:	[%d], [%i]\n", INT_MIN, INT_MAX);
	printf("Real:	[%u], [%u], [%u]\n", 0, 346983, INT_MAX);
	ft_printf("Mine:	[%u], [%u], [%u]\n", 0, 346983, INT_MAX);
	printf("Real:	[%x], [%X], [%x]\n", 0, 346983, INT_MAX);
	ft_printf("Mine:	[%x], [%X], [%x]\n", 0, 346983, INT_MAX);
	printf("Real:	[%%], [%%]\n");
	ft_printf("Mine:	[%%], [%%]\n");
	
	printf("***DASH/WIDTH TEST***\n");
	printf("Real:	[%-10c]\n", c);
	ft_printf("Mine:	[%-10c]\n", c);
	printf("Real:	[%-10s]\n", str1);
	ft_printf("Mine:	[%-10s]\n", str1);
	printf("Real:	STR = [%20s]\nReal:	PTR = [%20p]\n", str0, str0);
	ft_printf("Mine:	STR = [%20s]\nMine:	PTR = [%20p]\n", str0, str0);
	printf("Real:	STR = [%-20s]\nReal:	PTR = [%-20p]\n", str1, str1);
	ft_printf("Mine:	STR = [%-20s]\nMine:	PTR = [%-20p]\n", str1, str1);
	printf("Real:	[%-20d], [%20i]\n", INT_MIN, INT_MAX);
	ft_printf("Mine:	[%-20d], [%20i]\n", INT_MIN, INT_MAX);
	printf("Real:	[%-20d], [%20i]\n", 578, 578);
	ft_printf("Mine:	[%-20d], [%20i]\n", 578, 578);
	printf("Real:	[%10u], [%-10u], [%-20u]\n", 0, 346983, INT_MAX);
	ft_printf("Mine:	[%10u], [%-10u], [%-20u]\n", 0, 346983, INT_MAX);
	printf("Real:	[%x], [%10X], [%-20x]\n", 0, 346983, INT_MAX);
	ft_printf("Mine:	[%x], [%10X], [%-20x]\n", 0, 346983, INT_MAX);
	printf("Real:	[%%], [%%]\n");
	ft_printf("Mine:	[%%], [%%]\n");








	// printf("Real: [%-10c]\n", c);
	// ft_printf("Mine: [%-c]\n", c);
	// printf("Real: [%5p]\n", &c);
	// ft_printf("Mine: [%5p]\n", &c);
	// printf("Real: [%05d]\n", 123);
	// ft_printf("Mine: [%05d]\n", 123);
	// printf("Real: [%05d]\n", -50);
	// ft_printf("Mine: [%05d]\n", -50);
	// printf("Real: [%+05d]\n", 4);
	// ft_printf("Mine: [%+05d]\n", 4);
	// printf("Real: [%-+5d]\n", -42);
	// ft_printf("Mine: [%-+5d]\n", -42);
	// printf("v UNSIGNED v\n");
	// printf("Real: [%8u]\n", 997);
	// ft_printf("Mine: [%8u]\n", 997);
	// printf("Real: [%-8u]\n", 0);
	// ft_printf("Mine: [%-8u]\n", 0);
	// printf("Real: [%08u]\n", 997);
	// ft_printf("Mine: [%08u]\n", 997);
	// printf("v HEXA v\n");
	// printf("Real: [%-10x]\n", 56);
	// ft_printf("Mine: [%-10x]\n", 56);
	// printf("Real: [%10X]\n", 22);
	// ft_printf("Mine: [%10X]\n", 22);
	// printf("Real: [%010X]\n", 76);
	// ft_printf("Mine: [%010X]\n", 76);
	// printf("Real: [%0#10x]\n", 34);
	// ft_printf("Mine: [%0#10x]\n", 34);
	// printf("Real: [%0#10x]\n", 0);
	// ft_printf("Mine: [%0#10x]\n", 0);
	// printf("Real: [%0#2x]\n", 88);
	// ft_printf("Mine: [%0#2x]\n", 88);
	// printf("Real: [%%]\n");
	// ft_printf("Mine: [%%]\n");
	// printf("v PRECISION v\n");
	// printf("	CHARS	\n");
	// printf("Real: 		[%5.3s]\n", "Hello");
	// ft_printf("Mine: 		[%5.3s]\n", "Hello");
	// printf("Real: 		[%2.4s]\n", "Hello");
	// ft_printf("Mine: 		[%2.4s]\n", "Hello");
	// printf("Real: 		[%5.0s]\n", "Hello");
	// ft_printf("Mine: 		[%5.0s]\n", "Hello");
	// printf("	INTEGERS	\n");
	// printf("Real:		[%d]\n", 4224);
	// printf("Real:		[%+.d]\n", 4224);
	// printf("Real:		[%+.d]\n", -4224);
	// printf("Real: 		[%+.5d]\n", 4224);
	return (0);
}
