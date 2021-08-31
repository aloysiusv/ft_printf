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

// t_bool	print_signs(t_info *t, long di)
// {
// 	if (di < 0)
// 	{
// 		t->nbytes += write(1, "-", 1);
// 		return (TRUE);
// 	}
// 	if (di >= 0 && (t->flags & PLUS))
// 	{
// 		t->nbytes += write(1, "+", 1);
// 		return (TRUE);
// 	}
// 	if (t->flags & SPACE)
// 	{
// 		t->nbytes += write(1, " ", 1);
// 		return (TRUE);
// 	}
// 	return (FALSE);
// }

void	print_width(t_info *t, long len)
{
	while (t->width > len++)
	{
		if ((t->flags & ZERO_PAD) && t->prec < len)
			t->nbytes += write(1, "0", 1);
		else
			t->nbytes += write(1, " ", 1);
	}
}

// void	print_precision(t_info *t, long *len)
// {
// 	while (t->prec > *len++)
// 		t->nbytes += write(1, "0", 1);
// 	if (!(t->flags & DASH))
// 	{
// 		*len = t->prec;
// 		if (t->flags & PLUS)
// 			*len += 1;
// 	}
// }

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
	long 				len;

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

void	print_zero_prec(t_info *t)
{
	while (t->width-- > 0)
		t->nbytes += write(1, " ", 1);	
}

void	print_di(t_info *t, va_list ap)
{
	long	di;
	long	len;
	long	len_prec;

	di = va_arg(ap, int);
	len = ft_intlen_base(di, 10);
	len_prec = len;
	if ((t->flags & DOT) && t->prec == 0 && di == 0)
	{
		print_zero_prec(t);
		return ;
	}
	if ((t->flags & DOT) && t->prec >= len)
	{
		if (di < 0)
			t->prec += 1;
		if ((t->flags & PLUS) && di >= 0)
			t->prec += 1;
		len_prec = t->prec;
	}
	if ((t->flags & SPACE) && t->width <= len && di >= 0)
		t->nbytes += write(1, " ", 1);
	if ((t->flags & PLUS) && (t->flags & ZERO_PAD) && di >= 0)
		t->nbytes += write(1, "+", 1);
	if ((t->flags & ZERO_PAD) && di < 0)
		t->nbytes += write(1, "-", 1);
	if (t->flags & DASH)
	{
		if ((t->flags & PLUS) && !(t->flags & ZERO_PAD) && di >= 0)
			t->nbytes += write(1, "+", 1);
		if (!(t->flags & ZERO_PAD) && di < 0)
			t->nbytes += write(1, "-", 1);
		while (len_prec > len++)
			t->nbytes += write(1, "0", 1);
		long_putnbrbase(t, di, "0123456789", 10);
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
		if ((t->flags & PLUS) && !(t->flags & ZERO_PAD) && di >= 0)
			t->nbytes += write(1, "+", 1);
		if (!(t->flags & ZERO_PAD) && di < 0)
			t->nbytes += write(1, "-", 1);
		while (len_prec > len++)
			t->nbytes += write(1, "0", 1);
		long_putnbrbase(t, di, "0123456789", 10);
	}
}

void	print_u(t_info *t, va_list ap)
{
	unsigned int	u;
	long			len;
	long			len_prec;

	u = va_arg(ap, unsigned int);
	len = ft_ulllen_base(u, 10);
	len_prec = len;
	if ((t->flags & DOT) && t->prec == 0 && u == 0)
	{
		print_zero_prec(t);
		return ;
	}
	if ((t->flags & DOT) && t->prec > len)
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

void	print_xX(t_info *t, va_list ap, char *hash, char *base)
{
	unsigned int 	x;
	long			len;
	long			len_prec;
	x = va_arg(ap, unsigned int);
	len = ft_ulllen_base(x, 16);
	len_prec = len;
	if ((t->flags & DOT) && t->prec == 0 && x == 0)
	{
		print_zero_prec(t);
		return ;
	}
	if ((t->flags & DOT) && t->prec > len)
		len_prec = t->prec;
	if  ((t->flags & HASH) && x != 0)
		t->nbytes += write(1, hash, 2);
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

void	print_percent(t_info *t)
{
	char	c;

	c = '%';
	t->nbytes += write(1, &c, 1);
}