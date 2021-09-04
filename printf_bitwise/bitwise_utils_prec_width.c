/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_utils_prec_width.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 21:06:14 by lrandria          #+#    #+#             */
/*   Updated: 2021/09/04 21:06:14 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_padding(t_info *t, int len, int init_len)
{
	while (len > init_len++)
		t->nbytes += write(1, "0", 1);
}

void	print_pre_signs(t_info *t, int init_len, long di)
{
	if ((t->flags & SPACE) && t->width <= init_len && di >= 0)
		t->nbytes += write(1, " ", 1);
	if ((t->flags & PLUS) && (t->flags & ZERO_PAD) && di >= 0)
		t->nbytes += write(1, "+", 1);
	if ((t->flags & ZERO_PAD) && di < 0)
		t->nbytes += write(1, "-", 1);
}

void	print_post_signs(t_info *t, int len, int init_len, long di)
{
	if ((t->flags & PLUS) && !(t->flags & ZERO_PAD) && di >= 0)
		t->nbytes += write(1, "+", 1);
	if (!(t->flags & ZERO_PAD) && di < 0)
		t->nbytes += write(1, "-", 1);
	print_padding(t, len, init_len);
}

void	print_width(t_info *t, int len, long di)
{
	if (t->flags & HASH)
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
		print_width(t, 0, 0);
		return (TRUE);
	}
	return (FALSE);
}
