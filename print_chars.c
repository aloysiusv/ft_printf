/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 14:45:11 by lrandria          #+#    #+#             */
/*   Updated: 2021/09/05 14:45:11 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c_or_percent(t_info *t, va_list ap)
{
	char	c;

	c = (char)va_arg(ap, int);
	t->nbytes += write(1, &c, 1);
}

void	print_s(t_info *t, va_list ap)
{
	size_t	i;
	char	*s;

	i = 0;
	s = va_arg(ap, char *);
	if (s == NULL)
		t->nbytes += write(1, "(null)", 6);
	else
		while (s[i])
			t->nbytes += write(1, &s[i++], 1);
}
