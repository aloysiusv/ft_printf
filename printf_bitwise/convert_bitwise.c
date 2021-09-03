/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bitwise.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:56:12 by lrandria          #+#    #+#             */
/*   Updated: 2021/08/22 21:56:12 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pre_signs(t_info *t, int init_len, long di)
{
	if ((t->flags & SPACE) && t->width <= init_len && di >= 0)
		t->nbytes += write(1, " ", 1);
	if ((t->flags & PLUS) && (t->flags & ZERO_PAD) && di >= 0)
		t->nbytes += write(1, "+", 1);
	if ((t->flags & ZERO_PAD) && di < 0)
		t->nbytes += write(1, "-", 1);
}

void	print_post_signs(t_info *t, int len, int init_len, long di)
{
	if ((t->flags & PLUS) && !(t->flags & ZERO_PAD) && di >= 0)
		t->nbytes += write(1, "+", 1);
	if (!(t->flags & ZERO_PAD) && di < 0)
		t->nbytes += write(1, "-", 1);
	while (len > init_len++)
		t->nbytes += write(1, "0", 1);
}

void	adjust_len(t_info *t, int *len, long di)
{
	if (t->type == 'd' || t->type == 'i')
	{
		if (di < 0)
			t->prec += 1;
		if ((t->flags & PLUS) && di >= 0)
			t->prec += 1;
	}
	*len = t->prec;
}

void	print_padding(t_info *t, int len, int init_len)
{
	while (len > init_len++)
			t->nbytes += write(1, "0", 1);
}

void	print_width(t_info *t, int len)
{
	while (t->width-- > len)
	{
		if (t->flags & ZERO_PAD)
			t->nbytes += write(1, "0", 1); 
		else
			t->nbytes += write(1, " ", 1);	
	}
}

void	print_c(t_info *t, va_list ap)
{
	char	c;
	
	c = (char)va_arg(ap, int);
	if (t->flags & DASH)
		t->nbytes += write(1, &c, 1);
	if (t->width > 1)
		print_width(t, 1);
	if (!(t->flags & DASH))
		t->nbytes += write(1, &c, 1);
}

void	print_s(t_info *t, va_list ap)
{
	char	*s;
	int		len;

	s = va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	len = (int)ft_strlen(s);
	if ((t->flags & DOT) && t->prec < len)
		len = t->prec; 
	if (t->flags & DASH)
		t->nbytes += write(1, s, len);
	if (t->width > len)
		print_width(t, len);
	if (!(t->flags & DASH))
		t->nbytes += write(1, s, len);
}

void	print_p(t_info *t, va_list ap)
{
	unsigned long long	p;
	int 				len;

	p = va_arg(ap, unsigned long long);
	len = ft_ulllen_base(p, 16) + 2;
	if (!p)
	{
		p = 0;
		len = 3;
	}
	if (t->flags & DASH)
	{
		t->nbytes += write(1, "0x", 2);
		ull_putnbrbase(t, p, "0123456789abcdef", 16);
	}
	if (t->width > len)
		print_width(t, len);
	if (!(t->flags & DASH))
	{
		t->nbytes += write(1, "0x", 2);
		ull_putnbrbase(t, p, "0123456789abcdef", 16);
	}
}

void	print_di(t_info *t, va_list ap)
{
	long	di;
	int		init_len;
	int		len;

	di = va_arg(ap, int);
	init_len = ft_intlen_base(di, 10);
	len = init_len;
	if ((t->flags & DOT) && t->prec == 0 && di == 0)
	{
		print_width(t, 0);
		return ;
	}
	if ((t->flags & DOT) && t->prec >= init_len)
		adjust_len(t, &len, di);
	print_pre_signs(t, init_len, di);
	if (t->flags & DASH)
	{
		print_post_signs(t, len, init_len, di);
		long_putnbrbase(t, di, "0123456789", 10);
	}
	print_width(t, len);
	if (!(t->flags & DASH))
	{
		print_post_signs(t, len, init_len, di);
		long_putnbrbase(t, di, "0123456789", 10);
	}
}

void	print_u(t_info *t, va_list ap)
{
	unsigned int	u;
	int				init_len;
	int				len;

	u = va_arg(ap, unsigned int);
	init_len = ft_ulllen_base(u, 10);
	len = init_len;
	if ((t->flags & DOT) && t->prec == 0 && u == 0)
	{
		print_width(t, 0);
		return ;
	}
	if ((t->flags & DOT) && t->prec > init_len)
		adjust_len(t, &len, 0);
	if (t->flags & DASH)
	{
		print_padding(t, len, init_len);
		ull_putnbrbase(t, u, "0123456789", 10);
	}
	print_width(t, len);
	if (!(t->flags & DASH))
	{
		print_padding(t, len, init_len);
		ull_putnbrbase(t, u, "0123456789", 10);
	}
}

void	print_xX(t_info *t, va_list ap, char *hash, char *base)
{
	unsigned int 	x;
	int				init_len;
	int				len;
	
	x = va_arg(ap, unsigned int);
	init_len = ft_ulllen_base(x, 16);
	len = init_len;
	if ((t->flags & DOT) && t->prec == 0 && x == 0)
	{
		print_width(t, 0);
		return ;
	}
	if ((t->flags & DOT) && t->prec > init_len)
		adjust_len(t, &len, 0);
	if  ((t->flags & HASH) && x != 0)
		t->nbytes += write(1, hash, 2);
	if (t->flags & DASH)
	{
		print_padding(t, len, init_len);
		ull_putnbrbase(t, x, base, 16);
	}
	print_width(t, len);
	if (!(t->flags & DASH))
	{
		print_padding(t, len, init_len);
		ull_putnbrbase(t, x, base, 16);
	}
}

void	print_percent(t_info *t)
{
	t->nbytes += write(1, "%", 1);
}