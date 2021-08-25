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

void	print_c(t_info *t, va_list ap)
{
	char	c;
	
	c = (char)va_arg(ap, int);
	if (t->flags & DASH)
		t->nbytes += write(1, &c, 1);
	while (t->width-- > 1)
		t->nbytes += write(1, " ", 1);
	if (!(t->flags & DASH))
		t->nbytes += write(1, &c, 1);
}

void	print_s(t_info *t, va_list ap)
{
	char	*s;
	size_t	len;

	s = va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if ((t->flags & DOT) && t->prec < len)
		len = t->prec; 
	if (t->flags & DASH)
		t->nbytes += write(1, s, len);
	while (t->width-- > len)
		t->nbytes += write(1, " ", 1);
	if (!(t->flags & DASH))
		t->nbytes += write(1, s, len);
}

void	print_p_nil(t_info *t)
{
	if (t->flags & DASH)
		write(1, "\0", 1);
	while (t->width-- > 0)
		t->nbytes += write(1, " ", 1);
	if (!(t->flags & DASH))
		write(1, "\0", 1);
}

void	print_p(t_info *t, va_list ap)
{
	unsigned long long	p;
	unsigned long long 	len;

	p = va_arg(ap, unsigned long long);
	len = ft_ulllen_base(p, 16) + 2;
	if (!p)
	{
		print_p_nil(t);
		return ;
	}
	if (t->flags & DASH)
	{
		t->nbytes += write(1, "0x", 2);
		ull_putnbrbase(t, p, "0123456789abcdef", 16);
	}
	while (t->width-- > len)
		t->nbytes += write(1, " ", 1);
	if (!(t->flags & DASH))
	{
		t->nbytes += write(1, "0x", 2);
		ull_putnbrbase(t, p, "0123456789abcdef", 16);
	}
}

void	print_di(t_info *t, va_list ap)
{
	int		di;
	size_t	init_len;

	di = va_arg(ap, int);
	init_len = ft_intlen_base(di, 10);
	if ((t->flags & DOT) && t->prec == 0 && di == 0)
		t->nbytes += write(1, "\0", 0);
	if ((t->flags & DOT) && t->prec >= init_len && di != 0)
		if (di < 0)
			init_len -= 1;
	if ((t->flags & PLUS) && di >= 0)
		init_len += 1;
	if ((t->flags & SPACE) && t->width <= init_len && di >= 0)
		t->nbytes += write(1, " ", 1);
	if ((t->flags & PLUS) && (t->flags & ZERO_PAD) && di >= 0)
		t->nbytes += write(1, "+", 1);
	if ((t->flags & ZERO_PAD) && di < 0)
		t->nbytes += write(1, "-", 1);
	if (t->flags & DASH)
	{
		if (di < 0)
			t->nbytes += write(1, "-", 1);
		if ((t->flags & DOT) && t->prec > init_len)
			while (t->prec > init_len++)
				t->nbytes += write(1, "0", 1);
		long_putnbrbase(t, di, "0123456789", 10);
	}
	while (t->width-- > init_len)
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
		if ((t->flags & DOT) && t->prec > init_len)
			while (t->prec > init_len++)
				t->nbytes += write(1, "0", 1);
		long_putnbrbase(t, di, "0123456789", 10);
	}
}

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

void	print_percent(t_info *t)
{
	char	c;

	c = '%';
	t->nbytes += write(1, &c, 1);
}