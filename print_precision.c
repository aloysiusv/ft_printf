#include "ft_printf_bonus.h"

void	print_di_precision(t_info *t, va_list ap)
{
	int		di;
	size_t	len;

	len = 0;
	di = va_arg(ap, int);
	len = ft_intnbrlen(di);
		
		if (di == 0)
		{
			if (PREC == 0)
				
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
	else if (DOT == TRUE)
	{
		if (di == 0 && PREC == 0)
			while (WIDTH-- > 0)
				NBYTES += write(1, " ", 1);
		if (di >= PREC)
			NBYTES += write(1, &s[i++], 1);
	}