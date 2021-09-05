/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_print_more.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 03:24:04 by lrandria          #+#    #+#             */
/*   Updated: 2021/09/05 03:24:04 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_padding(t_info *t, int len, int init_len)
{
	while (len > init_len++)
		t->nbytes += write(1, "0", 1);
}

void	print_signs(t_info *t, long di)
{
	if ((t->flags & PLUS) && di >= 0)
		t->nbytes += write(1, "+", 1);
	if (di < 0)
		t->nbytes += write(1, "-", 1);
}

void	print_width(t_info *t, int len, long di, unsigned int x)
{
	if ((t->flags & HASH) && (t->type == 'x' ||t->type == 'X') && (x != 0))
		len += 2;
	if ((t->flags & PLUS) && (t->type == 'd' || t->type == 'i') && !(di < 0))
		len += 1;
	while (t->width-- > len)
	{
		if (t->flags & ZERO_PAD)
			t->nbytes += write(1, "0", 1);
		else
			t->nbytes += write(1, " ", 1);
	}
}

t_bool	print_nothing(t_info *t, long di)
{
	if ((t->flags & DOT) && t->prec == 0 && di == 0)
	{
		print_width(t, 0, 0, 0);
		return (TRUE);
	}
	return (FALSE);
}

void	print_extras(t_info *t, int init_len, long di)
{
	if (t->type == 'x')
	{
		if (t->flags & HASH)
			t->nbytes += write(1, "0x", 2);
	}
	else if (t->type == 'X')
	{
		if (t->flags & HASH)
			t->nbytes += write(1, "0X", 2);
	}
	else if (t->type == 'd' || t->type == 'i')
	{
		if ((t->flags & SPACE) && t->width <= init_len && di >= 0)
			t->nbytes += write(1, " ", 1);
		if (t->flags & ZERO_PAD)
			print_signs(t, di);
	}
}
