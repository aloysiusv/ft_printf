#include <stdio.h>
#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

void	ull_putnbrbase(t_info *t, unsigned long long nb, char *str, size_t base)
{
	unsigned long long	lol;

	lol = nb;
	if (lol >= base)
		ull_putnbrbase(t, lol / base, str, base);
	NBYTES += write(1, &str[lol % base], 1);
}

void	int_putnbrbase(t_info *t, long nb, char *str, int base)
{
	long	lol;

	if (nb >= 0)
		lol = nb;
	else
	{
		lol = -nb;
		NBYTES += write(1, "-", 1);
	}
	if (lol >= base)
		int_putnbrbase(t, lol / base, str, base);
	NBYTES += write(1, &str[lol % base], 1);
}

void	print_c(t_info *t, va_list ap)
{
	char	c;

	c = 0;
	c = (char)va_arg(ap, int);
	NBYTES += write(1, &c, 1);
}

void	print_s(t_info *t, va_list ap)
{
	size_t	i;
	char	*s;

	i = 0;
	s = va_arg(ap, char *);
	if (s == NULL)
		NBYTES += write(1, "(null)", 6);
	else
		while (s[i])
			NBYTES += write(1, &s[i++], 1);
}

void	print_p(t_info *t, va_list ap)
{
	unsigned long long	p;

	p = va_arg(ap, unsigned long long);
	if (!p)
		NBYTES += write(1, "(nil)", 5);
	else
	{
		NBYTES += write(1, "0x", 2);
		ull_putnbrbase(t, p, "0123456789abcdef", 16);
	}
}

void	print_di(t_info *t, va_list ap)
{
	int	di;

	di = va_arg(ap, int);
	int_putnbrbase(t, di, "0123456789", 10);
}

void	print_u(t_info *t, va_list ap)
{
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	ull_putnbrbase(t, u, "0123456789", 10);
}

void	print_xX(t_info *t, va_list ap)
{
	unsigned int	x;

	x = va_arg(ap, unsigned int);
	if (TYPE == 'x')
		ull_putnbrbase(t, x, "0123456789abcdef", 16);
	else if (TYPE == 'X')
		ull_putnbrbase(t, x, "0123456789ABCDEF", 16);
}

void	print_percent(t_info *t)
{
	(void)t;
	write(1, "%", 1);
}

void	go_to_conversion(t_info *t, va_list ap)
{
	if (TYPE == 'c' || TYPE == '%')
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

void 	reset_type(t_info *t)
{
	TYPE = '\0';
}

void	init_info(t_info *t)
{
	TYPE = '\0';
	NBYTES = 0;
}

size_t	do_your_magic(const char *str, t_info *t, va_list ap)
{
	size_t	i;

	i = 0;
	init_info(t);
	while (str[i])
	{
		if (str[i] == '%')
		{
			reset_type(t);
			i++;
			TYPE = str[i];
			if (if_symbol("cspdiuxX%", TYPE) == TRUE)
				go_to_conversion(t, ap);
		}
		else
			NBYTES += write(1, &str[i], 1);
		i++;
	}
	return (NBYTES);
}

int ft_printf(const char *format, ...)
{
	va_list		ap;
	t_info	t[1];
	
	va_start(ap, format);
	NBYTES = do_your_magic(format, t, ap);
	va_end(ap);

	return (NBYTES);
}

int main(void)
{
	// C //
	// printf("Real [%c]\n", '0');
	// ft_printf("Mine [%c]\n", '0');
	// printf("Real [ %c ]\n", '0');
	// ft_printf("Mine [ %c ]\n", '0');
	// printf("Real [ %c]\n", '0' - 256);
	// ft_printf("Mine [ %c]\n", '0' - 256);
    // printf("Real [%c ]\n", '0' + 256);
	// ft_printf("Mine [%c ]\n", '0' + 256);
	// printf("Real [%c %c %c] \n", '0', 0, '1');
	// ft_printf("Mine [%c %c %c] \n", '0', 0, '1');
    // printf("Real [%c %c %c] \n", ' ', ' ', ' ');
	// ft_printf("Mine [%c %c %c] \n", ' ', ' ', ' ');
    // printf("Real [%c %c %c] \n", '1', '2', '3');
	// ft_printf("Mine [%c %c %c] \n", '1', '2', '3');
    // printf("Real [%c %c %c] \n", '2', '1', 0);
	// ft_printf("Mine [%c %c %c] \n", '2', '1', 0);
	// printf("Real [%c %c %c] \n", 0, '1', '2');
	// ft_printf("Mine [%c %c %c] \n", 0, '1', '2');

	// printf("***STRINGS***\n");

    // printf("Real [%s]\n", "");
	// ft_printf("Mine [%s]\n", "");
    // printf("Real [ %s]\n", "");
	// ft_printf("Mine [ %s]\n", "");
    // printf("Real [%s ]\n", "");
	// ft_printf("Mine [%s ]\n", "");
    // printf("Real [ %s ]\n", "");
	// ft_printf("Mine [ %s ]\n", "");
    // printf("Real [ %s ]\n", "-");
	// ft_printf("Mine [ %s ]\n", "-");
    // printf("Real [ %s %s ]\n", "", "-");
	// ft_printf("Mine [ %s %s ]\n", "", "-");
    // printf("Real [ %s %s ]\n", " - ", "");
	// ft_printf("Mine [ %s %s ]\n", " - ", "");
    // printf("Real [ %s %s %s %s ]\n", " - ", "", "4", "");
	// ft_printf("Mine [ %s %s %s %s ]\n", " - ", "", "4", "");
    // printf("Real [ %s %s %s %s %s ]\n", " - ", "", "4", "", "2 ");
	// ft_printf("Mine [ %s %s %s %s %s ]\n", " - ", "", "4", "", "2 ");
	// printf("RET REAL = [%d]\n", printf(" %%%% "));
	// printf("RET MINE = [%d]\n", ft_printf(" %%%% "));  
	// printf("RET REAL = [%d]\n", printf(" %% "));
	// printf("RET MINE = [%d]\n", ft_printf(" %% "));
    // printf("RET REAL = [%d]\n", printf(" %% %% %% "));
    // printf("RET MINE = [%d]\n", ft_printf(" %% %% %% "));
    // printf("RET REAL = [%d]\n", printf(" %%  %%  %% "));
    // printf("RET MINE = [%d]\n", ft_printf(" %%  %%  %% "));
    // printf("RET REAL = [%d]\n", printf(" %%   %%   %% "));
    // printf("RET MINE = [%d]\n", ft_printf(" %%   %%   %% "));
    // printf("RET REAL = [%d]\n", printf("%%"));
    // printf("RET MINE = [%d]\n", ft_printf("%%"));
    // printf("RET REAL = [%d]\n", printf("%% %%"));
    // printf("RET MINE = [%d]\n", ft_printf("%% %%"));

	return (0);
}
