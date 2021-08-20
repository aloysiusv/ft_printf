#include "ft_printf.h"

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
		NBYTES += write(1, "(null)", 6);
	if (DOT == FALSE)
		while (s[i])
		{
			if (DASH == TRUE)
				NBYTES += write(1, &s[i++], 1);
			len = 0;
			len = ft_strlen(s) + 1;
			if (WIDTH > len)
			{
				WIDTH = WIDTH - len;
				while (--WIDTH > 0)
					NBYTES += write(1, " ", 1);
			}
			if (DASH == FALSE)
				NBYTES += write(1, &s[i++], 1);
		}
	else if (DOT == TRUE)
	{
		while (WIDTH-- > PREC)
			NBYTES += write(1, " ", 1);
		while (i < PREC)
			NBYTES += write(1, &s[i++], 1);
	}
}

void	print_p(t_info *t, va_list ap)
{
	unsigned long long	p;
	unsigned long long 	len;

	p = va_arg(ap, unsigned long long);
	if (!p)
		NBYTES += write(1, "(nil)", 5);
	if (DASH == TRUE)
	{
		NBYTES += write(1, "0x", 2);
		ull_putnbrbase(t, p, "0123456789abcdef", 16);
	}
	len = 0;
	len = ft_ulllen(p) + 2;
	if (WIDTH > len)
	{
		WIDTH = WIDTH - len;
		while (WIDTH-- > 0)
			NBYTES += write(1, " ", 1);
	}
	if (DASH == FALSE)
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
		while (WIDTH--  > 0)
		{
			if (ZERO_PAD == TRUE)
				NBYTES += write(1, "0", 1); 
			else
				NBYTES += write(1, " ", 1);
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
	len = ft_ulllen(u);
	if (u == 0)
		len = len + 1;
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
	len = ft_ulllen(x);
	if (x == 0)
		len = len + 1;
	if (TYPE == 'x')
	{
		if  (HASH == TRUE && x != 0)
		{
			NBYTES += write(1, "0x", 2);
			len = len + 2;
		}
		if (DASH == TRUE)
			ull_putnbrbase(t, x, "0123456789abcdef", 16);
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
			ull_putnbrbase(t, x, "0123456789abcdef", 16);
	}
	else if (TYPE == 'X')
	{
		if  (HASH == TRUE && x != 0)
		{
			NBYTES += write(1, "0X", 2);
			len = len + 2;
		}
		if (DASH == TRUE)
			ull_putnbrbase(t, x, "0123456789ABCDEF", 16);
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
			ull_putnbrbase(t, x, "0123456789ABCDEF", 16);
	}
}

void	print_percent(t_info *t)
{
	NBYTES += write(1, "%", 1);
}