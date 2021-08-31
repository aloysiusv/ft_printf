#include "ft_printf.h"

void	print_zero_prec(t_info *t)
{
	while (t->width-- != 0)
		t->nbytes += write(1, " ", 1);	
}

void	print_di(t_info *t, va_list ap)
{
	int		di;
	size_t	len;

	di = va_arg(ap, int);
	len = ft_intlen_base(di, 10);
	if ((t->flags & DOT) && t->prec == 0 && di == 0)
	{
		print_zero_prec(t);
		return ;
	}
	if ((t->flags & DOT) && t->prec >= len && di < 0)
		len -= 1;
	if ((t->flags & PLUS) && di >= 0)
		len += 1;
	if ((t->flags & SPACE) && t->width <= len && di >= 0)
		t->nbytes += write(1, " ", 1);
	if ((t->flags & PLUS) && (t->flags & ZERO_PAD) && di >= 0)
		t->nbytes += write(1, "+", 1);
	if ((t->flags & ZERO_PAD) && di < 0)
		t->nbytes += write(1, "-", 1);
	if (t->flags & DASH)
	{
		if (di < 0)
			t->nbytes += write(1, "-", 1);
		if ((t->flags & DOT) && t->prec > len)
		{
			while (t->prec > len++)
				t->nbytes += write(1, "0", 1);
			len = t->prec;
		}
		long_putnbrbase(t, di, "0123456789", 10);
	}
	if (!(t->flags & DOT))
		while (t->width-- > len)
		{
			if (t->flags & ZERO_PAD)
				t->nbytes += write(1, "0", 1); 
			else
				t->nbytes += write(1, " ", 1);	
		}
	if ((t->flags & PLUS) && !(t->flags & ZERO_PAD) && di >= 0)
		t->nbytes += write(1, "+", 1);
	if (!(t->flags & DASH))
	{
		if (!(t->flags & ZERO_PAD) && di < 0)
			t->nbytes += write(1, "-", 1);
		if ((t->flags & DOT) && t->prec > len)
		{
			while (t->prec != 0  && t->prec > len++)
				t->nbytes += write(1, "0", 1);
			len = t->prec;
		}
		long_putnbrbase(t, di, "0123456789", 10);
	}
}
