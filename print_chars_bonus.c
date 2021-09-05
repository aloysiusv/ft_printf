/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 14:33:44 by lrandria          #+#    #+#             */
/*   Updated: 2021/09/05 14:33:44 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_c(t_info *t, va_list ap)
{
	char	c;

	c = (char)va_arg(ap, int);
	if (t->flags & DASH)
		t->nbytes += write(1, &c, 1);
	if (t->width > 1)
		print_width(t, 1, 0, 0);
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
		adjust_len(t, &len, 0, 0);
	if (t->flags & DASH)
		t->nbytes += write(1, s, len);
	if (t->width > len)
		print_width(t, len, 0, 0);
	if (!(t->flags & DASH))
		t->nbytes += write(1, s, len);
}

void	print_percent(t_info *t)
{
	t->nbytes += write(1, "%", 1);
}
