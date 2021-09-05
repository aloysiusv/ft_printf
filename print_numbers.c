/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 14:46:27 by lrandria          #+#    #+#             */
/*   Updated: 2021/09/05 14:46:27 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p(t_info *t, va_list ap)
{
	unsigned long long	p;

	p = va_arg(ap, unsigned long long);
	if (!p)
		t->nbytes += write(1, "0x0", 3);
	else
	{
		t->nbytes += write(1, "0x", 2);
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

void	print_hex(t_info *t, va_list ap)
{
	unsigned int	x;

	x = va_arg(ap, unsigned int);
	if (t->type == 'x')
		ull_putnbrbase(t, x, "0123456789abcdef", 16);
	else if (t->type == 'X')
		ull_putnbrbase(t, x, "0123456789ABCDEF", 16);
}
