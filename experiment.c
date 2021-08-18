#include <stdio.h>
#include <unistd.h>

#include "ft_printf_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	int_len(int n)
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


void	ft_ulltoa(t_info *t, unsigned long long n)
{
	unsigned long long	nb;
	char				*n_ascii;
	size_t				len;

	len = int_len(n);
	n_ascii = (char *)malloc(sizeof(char) * (len + 1));
	if (n_ascii == NULL)
		return (0);
	n_ascii[len] = '\0';
	nb = n;
	if (n == 0)
		n_ascii[0] = '0';
	while (nb)
	{
		n_ascii[len - 1] = nb % 10 + '0';
		nb /= 10;
		len--;
	}
	NUM_ASCII = n_ascii;
	free(n_ascii);
}


void	store_flags(t_info *t,  char i)
{
	if (i == ' ' && PLUS == FALSE)
		SPACE = TRUE;
	else if (i == '-')
	{
		DASH = TRUE;
		ZERO_PAD = FALSE;
	}
	else if (i == '0' && DASH == FALSE && DOT == FALSE)
		ZERO_PAD = TRUE;
	else if (i == '.')
	{
		DOT = TRUE;
		ZERO_PAD = FALSE;
	}
	else if (i == '#')
		HASH = TRUE;
	else if (i == '+')
	{
		PLUS = TRUE;
		SPACE = FALSE;
	}
}

void	store_width(t_info *t, const char *str, size_t *i)
{
	char 	*width_ascii;
	size_t	len;
	size_t	j;
	size_t	k;

	len = 0;
	j = *i;
	while (if_symbol(ALLTYPES, str[j]) == FALSE)
	{
		if (str[j] >= '0' && str[j] <= '9')
			len++;
		j++;
	}
	width_ascii = (char *)malloc(sizeof(char) * len + 1);
	if (width_ascii == NULL)
		return ;
	k = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		width_ascii[k++] = str[*i];
		*i += 1;
	}
	width_ascii[k] = '\0';
	WIDTH = ft_atoui((const char *)width_ascii);
	free(width_ascii);
}

void	store_precision(t_info *t, const char *str, size_t *i)
{
	char 	*precision_ascii;
	size_t	len;
	size_t	j;
	size_t	k;

	len = 0;
	j = *i;
	while (if_symbol(ALLTYPES, str[j]) == FALSE)
	{
		if (str[j] >= '0' && str[j] <= '9')
			len++;
		j++;
	}
	precision_ascii = (char *)malloc(sizeof(char) * len + 1);
	if (precision_ascii == NULL)
		return ;
	k = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		precision_ascii[k++] = str[*i];
		*i += 1;
	}
	precision_ascii[k] = '\0';
	PREC = ft_atoui((const char *)precision_ascii);
	free(precision_ascii);
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
	{
		lol = -nb;
		NBYTES += write(1, "-", 1);
	}
	if (lol >= base)
		long_putnbrbase(t, lol / base, str, base);
	NBYTES += write(1, &str[lol % base], 1);
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
	size_t	i;
	char	*s;

	i = 0;
	s = va_arg(ap, char *);
	if (s == NULL)
		NBYTES += write(1, "(null)", 6);
	while (s[i])
	{
		if (DASH == TRUE)
			NBYTES += write(1, &s[i++], 1);
		if (WIDTH > 0)
		{
			WIDTH = WIDTH - ft_strlen(s + 1);
			while (--WIDTH > 0)
				NBYTES += write(1, " ", 1);
		}
		if (DASH == FALSE)
			NBYTES += write(1, &s[i++], 1);
	}
}

void	print_p(t_info *t, va_list ap)
{
	unsigned long long	p;

	p = va_arg(ap, unsigned long long);
	if (!p)
		NBYTES += write(1, "(nil)", 5);
	if (DASH == TRUE)
	{
		NBYTES += write(1, "0x", 2);
		ull_putnbrbase(t, p, "0123456789abcedf", 16);
	}
	if (WIDTH > 0)
	{
		WIDTH = WIDTH - (ft_strlen(NUM_ASCII));
		while (--WIDTH > 0)
		{
			 
		}
			NBYTES += write(1, " ", 1);
	}
	if (DASH == FALSE)
	{
		NBYTES += write(1, "0x", 2);
		ull_putnbrbase(t, p, "0123456789abcedf", 16);
	}
}

void	print_di(t_info *t, va_list ap)
{
	int	di;

	di = va_arg(ap, int);
	if (PLUS == TRUE)
		NBYTES += write(1, "+", 1);
	if (SPACE == TRUE && WIDTH == 0)
		NBYTES += write(1, " ", 1);
	if (DASH == TRUE)
		long_putnbrbase(t, di, "0123456789", 10);
	if (WIDTH > 0)
		while (--WIDTH > 0)
		{
			if (ZERO_PAD == TRUE)
				NBYTES += write(1, "0", 1); 
			else
				NBYTES += write(1, " ", 1);
		}
	if (DASH == FALSE)
		long_putnbrbase(t, di, "0123456789", 10);
}

void	print_u(t_info *t, va_list ap)
{
	unsigned int u;

	u = va_arg(ap, unsigned int);
	if (PLUS == TRUE)
		NBYTES += write(1, "+", 1);
	if (DASH == TRUE)
		ull_putnbrbase(t, u, "0123456789", 10);
	if (WIDTH > 0)
		while (--WIDTH > 0)
		{
			if (ZERO_PAD == TRUE)
				NBYTES += write(1, "0", 1); 
			else
				NBYTES += write(1, " ", 1);
		}
	if (DASH == FALSE)
		ull_putnbrbase(t, u, "0123456789", 10);
}

void	print_xX(t_info *t, va_list ap)
{
	unsigned int x;

	x = va_arg(ap, unsigned int);
	if (TYPE == 'x')
	{
		if (HASH == TRUE)
			NBYTES += write(1, "0x", 2);
		ull_putnbrbase(t, x, "0123456789abcdef", 16);
	}
	else
	{
		if (HASH == TRUE)
			NBYTES += write(1, "0X", 2);
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

void	init_info(t_info *t)
{
	SPACE = FALSE;
	DASH = FALSE;
	ZERO_PAD = FALSE;
	DOT = FALSE;
	HASH = FALSE;
	PLUS = FALSE;
	NUM_ASCII = '\0';
	TYPE = '\0';
	WIDTH = 0;
	PREC = 0;
	NBYTES = 0;
}

size_t	do_your_magic(const char *str, t_info *t, va_list ap)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			init_info(t);
			while (if_symbol(ALLFLAGS, str[i]) == TRUE)
			{
				store_flags(t, str[i]);
				i++;
			}
			while (str[i] >= '1' && str[i] <= '9')
				store_width(t, str, &i);
			if (DOT == TRUE)
				// if (str[i + 1] >= '1' && str[i + 1] <= '9')
					store_precision(t, str, &i);
			if (if_symbol("cspdiuxX%", str[i]) == TRUE)
			{
				TYPE = str[i];
				go_to_conversion(t, ap);
			}
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

int	main(void)
{
	
	// printf("Real: [%16c]\n", 'K');
	// ft_printf("Mine: [%16c]\n", 'K');
	printf("Real: [% +10s]\n", "b");
	ft_printf("Mine: [% +10s]\n", "b");
	printf("Real: [% 0+10p]\n", 'K');
	ft_printf("Mine: [% 0+10p]\n", 'K');
	// ft_printf("Mine: [% 22i]\n", 9);
	return (0);
}
