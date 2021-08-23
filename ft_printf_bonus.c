/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 18:40:22 by lrandria          #+#    #+#             */
/*   Updated: 2021/08/14 18:40:22 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	reset_info(t_info *t)
{
	SPACE = FALSE;
	DASH = FALSE;
	ZERO_PAD = FALSE;
	DOT = FALSE;
	HASH = FALSE;
	PLUS = FALSE;
	TYPE = '\0';
	WIDTH = 0;
	PREC = 1;
}

void	init_info(t_info *t)
{
	SPACE = FALSE;
	DASH = FALSE;
	ZERO_PAD = FALSE;
	DOT = FALSE;
	HASH = FALSE;
	PLUS = FALSE;
	TYPE = '\0';
	WIDTH = 0;
	PREC = 1;
	NBYTES = 0;
	POS = 0;
}

size_t	do_your_magic(const char *str, t_info *t, va_list ap)
{
	init_info(t);
	while (str[POS])
	{
		if (str[POS] == '%')
		{
			reset_info(t);
			analyse_conversion(t, str, ap);
		}
		else
			NBYTES += write(1, &str[POS], 1);
		POS++;
	}
	return (NBYTES);
}

int ft_printf(const char *format, ...)
{
	va_list	ap;
	t_info	t[1];
	
	if (format == NULL)
		return (-1);
	va_start(ap, format);
	NBYTES = do_your_magic(format, t, ap);
	va_end(ap);

	return (NBYTES);
}
