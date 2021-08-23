/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bitwise.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 22:08:00 by lrandria          #+#    #+#             */
/*   Updated: 2021/08/22 22:08:00 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

unsigned int	if_symbol(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

size_t	ft_atoui(const char *str)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res);
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