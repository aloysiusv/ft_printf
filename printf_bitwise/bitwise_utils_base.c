/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_utils_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 21:04:08 by lrandria          #+#    #+#             */
/*   Updated: 2021/09/04 21:04:08 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_ulllen_base(unsigned long long n, size_t base_len)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len = len + 1;
	while (n)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

size_t	ft_intlen_base(int n, size_t base_len)
{
	long	n_long;
	size_t	len;

	len = 0;
	n_long = n;
	if (n <= 0)
	{
		n_long = -n_long;
		len += 1;
	}
	while (n_long)
	{
		n_long /= base_len;
		len++;
	}
	return (len);
}

void	ull_putnbrbase(t_info *t, unsigned long long nb, char *str, size_t base)
{
	unsigned long long	lol;

	lol = nb;
	if (lol >= base)
		ull_putnbrbase(t, lol / base, str, base);
	t->nbytes += write(1, &str[lol % base], 1);
}

void	long_putnbrbase(t_info *t, int nb, char *str, long base)
{
	long	lol;

	lol = nb;
	if (nb < 0)
		lol = -lol;
	if (lol >= base)
		long_putnbrbase(t, lol / base, str, base);
	t->nbytes += write(1, &str[lol % base], 1);
}
