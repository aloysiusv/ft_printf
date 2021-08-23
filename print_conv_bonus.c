/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conv_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 14:42:41 by lrandria          #+#    #+#             */
/*   Updated: 2021/08/22 14:42:41 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_c(t_info *t, va_list ap)
{
	char	c;
	
	c = (char)va_arg(ap, int);
	if (DASH == TRUE)
		NBYTES += write(1, &c, 1);
	while (WIDTH-- > 1)
		NBYTES += write(1, " ", 1);
	if (DASH == FALSE)
		NBYTES += write(1, &c, 1);
}

void	print_s(t_info *t, va_list ap)
{
	char	*s;
	size_t	len;

	s = va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (DASH == TRUE)
		NBYTES += write(1, s, len);
	while (WIDTH-- > len)
		NBYTES += write(1, " ", 1);
	if (DASH == FALSE)
		NBYTES += write(1, s, len);
}

void	print_p_nil(t_info *t)
{
	if (DASH == TRUE)
		NBYTES += write(1, "(nil)", 5);
	while (WIDTH-- > 5)
		NBYTES += write(1, " ", 1);
	if (DASH == FALSE)
		NBYTES += write(1, "(nil)", 5);
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
	if (DASH == TRUE)
	{
		NBYTES += write(1, "0x", 2);
		ull_putnbrbase(t, p, "0123456789abcdef", 16);
	}
	while (WIDTH-- > len)
		NBYTES += write(1, " ", 1);
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

	di = va_arg(ap, int);
	len = ft_intlen_base(di, 10);
	if (PLUS == TRUE && di >= 0)
		len += 1;

	if (SPACE == TRUE && WIDTH <= len && di >= 0)
		NBYTES += write(1, " ", 1);

	if (PLUS == TRUE && ZERO_PAD == TRUE && di >= 0)
		NBYTES += write(1, "+", 1);
	if (ZERO_PAD == TRUE && di < 0)
		NBYTES += write(1, "-", 1);
	if (DASH == TRUE)
	{
		if (di < 0)
			NBYTES += write(1, "-", 1);
		long_putnbrbase(t, di, "0123456789", 10);
	}

	while (WIDTH-- > len)
	{
		if (ZERO_PAD == TRUE)
			NBYTES += write(1, "0", 1); 
		else
			NBYTES += write(1, " ", 1);	
	}

	if (PLUS == TRUE && ZERO_PAD == FALSE && di >= 0)
		NBYTES += write(1, "+", 1);
	if (DASH == FALSE)
	{
		if (ZERO_PAD == FALSE && di < 0)
			NBYTES += write(1, "-", 1);
		long_putnbrbase(t, di, "0123456789", 10);
	}
}

void	print_u(t_info *t, va_list ap)
{
	unsigned int	u;
	size_t			len;

	u = va_arg(ap, unsigned int);
	len = ft_ulllen_base(u, 10);
	if (DASH == TRUE)
		ull_putnbrbase(t, u, "0123456789", 10);
	while (WIDTH-- > len)
	{
		if (ZERO_PAD == TRUE)
			NBYTES += write(1, "0", 1); 
		else
			NBYTES += write(1, " ", 1);
	}
	if (DASH == FALSE)
		ull_putnbrbase(t, u, "0123456789", 10);
}

void	print_xX(t_info *t, va_list ap, char *hash, char *base)
{
	unsigned int 	x;
	size_t			len;

	x = va_arg(ap, unsigned int);
	len = ft_ulllen_base(x, 16);
	if  (HASH == TRUE && x != 0)
	{
		NBYTES += write(1, hash, 2);
		len = len + 2;
	}
	if (DASH == TRUE)
		ull_putnbrbase(t, x, base, 16);
	while (WIDTH-- > len)
	{
		if (ZERO_PAD == TRUE)
			NBYTES += write(1, "0", 1); 
		else
			NBYTES += write(1, " ", 1);
	}
	if (DASH == FALSE)
		ull_putnbrbase(t, x, base, 16);
}

void	print_percent(t_info *t)
{
	char	c;

	c = '%';
	NBYTES += write(1, &c, 1);
}
