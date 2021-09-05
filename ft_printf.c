/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:16:16 by lrandria          #+#    #+#             */
/*   Updated: 2021/08/09 19:54:42 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	go_to_conversion(t_info *t, va_list ap)
{
	if (t->type == 'c' || t->type == '%')
		print_c_or_percent(t, ap);
	if (t->type == 's')
		print_s(t, ap);
	if (t->type == 'p')
		print_p(t, ap);
	if (t->type == 'd' || t->type == 'i')
		print_di(t, ap);
	if (t->type == 'u')
		print_u(t, ap);
	if (t->type == 'x' || t->type == 'X')
		print_hex(t, ap);
}

void	reset_type(t_info *t)
{
	t->type = '\0';
}

void	init_info(t_info *t)
{
	t->type = '\0';
	t->nbytes = 0;
}

size_t	do_your_magic(const char *str, t_info *t, va_list ap)
{
	size_t	i;

	i = 0;
	init_info(t);
	while (str[i])
	{
		if (str[i] == '%')
		{
			reset_type(t);
			i++;
			t->type = str[i];
			if (t->type == '%')
				t->nbytes += write(1, "%", 1);
			else if (if_symbol("cspdiuxX", t->type) == TRUE)
				go_to_conversion(t, ap);
		}
		else
			t->nbytes += write(1, &str[i], 1);
		i++;
	}
	return (t->nbytes);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_info		t[1];

	va_start(ap, format);
	t->nbytes = do_your_magic(format, t, ap);
	va_end(ap);
	return (t->nbytes);
}
