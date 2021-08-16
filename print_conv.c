/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 18:57:53 by lrandria          #+#    #+#             */
/*   Updated: 2021/08/14 18:57:53 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c_or_percent(t_info *t, va_list ap)
{
	char	c;

	if (TYPE == '%')
		NBYTES += write(1, "%", 1);
	else
	{
		c = 0;
		c = (char)va_arg(ap, int);
		NBYTES += write(1, &c, 1);
	}
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
			NBYTES += write(1, &s[i++], 1);
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
	int_putnbrbase(t, di, "0123456789", 10);
}

void	print_u(t_info *t, va_list ap)
{
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	ull_putnbrbase(t, u, "0123456789", 10);
}

void	print_xX(t_info *t, va_list ap)
{
	unsigned int	x;

	x = va_arg(ap, unsigned int);
	if (TYPE == 'x')
		ull_putnbrbase(t, x, "0123456789abcedf", 16);
	else
		ull_putnbrbase(t, x, "0123456789ABCDEF", 16);
}