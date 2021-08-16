#include "ft_printf_bonus.h"

void	print_c(t_info *t, va_list ap)
{
	char	c;
	
	c = 0;
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
	else
		while (s[i])
		{
			if (DASH == TRUE)
				NBYTES += write(1, &s[i++], 1);
			if (WIDTH > 0)
				while (--WIDTH > 0)
				{
					if (ZERO_PAD == TRUE)
						NBYTES += write(1, "0", 1); 
					else
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
	else
	{
		NBYTES += write(1, "0x", 2);
		ull_putnbrbase(t, p, "0123456789abcedf", 16);
	}
}

void	print_di(t_info *t, va_list ap)
{
	int	di;

	di = va_arg(ap, int);
	if (DASH == TRUE)
		int_putnbrbase(t, di, "0123456789", 10);
	if (WIDTH > 0)
		while (--WIDTH > 0)
		{
			if (ZERO_PAD == TRUE)
				NBYTES += write(1, "0", 1); 
			else
				NBYTES += write(1, " ", 1);
		}
	if (DASH == FALSE)
		int_putnbrbase(t, di, "0123456789", 10);
}

void	print_u(t_info *t, va_list ap)
{
	unsigned int u;

	u = va_arg(ap, unsigned int);
	if (DASH == TRUE)
		ull_putnbrbase(t, di, "0123456789", 10);
	if (WIDTH > 0)
		while (--WIDTH > 0)
		{
			if (ZERO_PAD == TRUE)
				NBYTES += write(1, "0", 1); 
			else
				NBYTES += write(1, " ", 1);
		}
	if (DASH == FALSE)
		ull_putnbrbase(t, di, "0123456789", 10);
}

void	print_xX(t_info *t, va_list ap)
{
	unsigned int x;

	x = va_arg(ap, unsigned int);
	if (TYPE == 'x')
	{
		if (HASH == TRUE)
			NBYTES += write(1, "0x", 2);
		ull_putnbrbase(t, x, "0123456789abcedf", 16);
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