/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_bitwise.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:35:07 by lrandria          #+#    #+#             */
/*   Updated: 2021/08/22 21:35:07 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_info(t_info *t)
{
	t->flags = 0;
	t->type = '\0';
	t->prec = -1;
	t->width = 0;
}

void	init_info(t_info *t)
{
	t->flags = 0;
	t->type = '\0';
	t->prec = -1;
	t->width = 0;
	t->nbytes = 0;
	t->pos = 0;
}

size_t	do_your_magic(const char *str, t_info *t, va_list ap)
{
	init_info(t);
	while (str[t->pos])
	{
		if (str[t->pos] == '%')
		{
			reset_info(t);
			analyse_conversion(t, str, ap);
		}
		else
			t->nbytes += write(1, &str[t->pos], 1);
		t->pos++;
	}
	return (t->nbytes);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_info	t[1];

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	t->nbytes = do_your_magic(format, t, ap);
	va_end(ap);
	return (t->nbytes);
}
