/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_print_numbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 21:08:48 by lrandria          #+#    #+#             */
/*   Updated: 2021/09/04 21:08:48 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p(t_info *t, va_list ap)
{
	unsigned long long	p;
	int					len;

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
		print_width(t, len, 0, 0);
	if (!(t->flags & DASH))
	{
		t->nbytes += write(1, "0x", 2);
		ull_putnbrbase(t, p, "0123456789abcdef", 16);
	}
}

void	final_di(t_info *t, int len, int init_len, long di)
{
	if (!(t->flags & ZERO_PAD))
		print_signs(t, di);
	print_padding(t, len, init_len);
	long_putnbrbase(t, di, "0123456789", 10);
}

void	print_di(t_info *t, va_list ap)
{
	long	di;
	int		init_len;
	int		len;

	di = va_arg(ap, int);
	init_len = ft_intlen_base(di, 10);
	len = init_len;
	if (print_nothing(t, di) == TRUE)
		return ;
	adjust_len(t, &len, init_len, di);
	print_extras(t, init_len, di);
	if (t->flags & DASH)
		final_di(t, len, init_len, di);
	print_width(t, len, di, 0);
	if (!(t->flags & DASH))
		final_di(t, len, init_len, di);
}

void	print_u(t_info *t, va_list ap)
{
	unsigned int	u;
	int				init_len;
	int				len;

	u = va_arg(ap, unsigned int);
	init_len = ft_ulllen_base(u, 10);
	len = init_len;
	if (print_nothing(t, u) == TRUE)
		return ;
	adjust_len(t, &len, init_len, 0);
	if (t->flags & DASH)
	{
		print_padding(t, len, init_len);
		ull_putnbrbase(t, u, "0123456789", 10);
	}
	print_width(t, len, 0, 0);
	if (!(t->flags & DASH))
	{
		print_padding(t, len, init_len);
		ull_putnbrbase(t, u, "0123456789", 10);
	}
}

void	print_xX(t_info *t, va_list ap, char *base)
{
	unsigned int	x;
	int				init_len;
	int				len;

	x = va_arg(ap, unsigned int);
	init_len = ft_ulllen_base(x, 16);
	len = init_len;
	if (print_nothing(t, x) == TRUE)
		return ;
	adjust_len(t, &len, init_len, 0);
	if (x != 0)
		print_extras(t, init_len, 0);
	if (t->flags & DASH)
	{
		print_padding(t, len, init_len);
		ull_putnbrbase(t, x, base, 16);
	}
	print_width(t, len, 0, x);
	if (!(t->flags & DASH))
	{
		print_padding(t, len, init_len);
		ull_putnbrbase(t, x, base, 16);
	}
}
