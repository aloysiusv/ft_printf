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

void	check_flags(const char *format, t_info *t)
{
	while (format[END])
		{
			if (format[END] == '%')
		
}

void	init_info(t_info *t)
{
	SPACE = false;
	DASH = false;
	ZERO_PAD = false;
	IF_PREC = false;
	HASH = false;
	PLUS = false;
	TYPE = '\0';
	START = 0;
	END = 0;
	WIDTH = 0;
	PREC = 0;
	NBYTES = 0;
}

int ft_printf(const char *format, ...)
{
	// va_list		ap;
	t_info		t[1];
	
	// if (!(check_format_error(format)))
	// 	return (-1);
	if (if_symbol(format, '%') == false)
		NBYTES = write(1, format, ft_strlen(format));
	else
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			NBYTES += write(1, &format[i], 1);
			i++;
		}
		else
		{
			check_flags(format, &i, t);
			go_convert(t);
			go_print(t);
			i++;
		}
	va_end(ap);
	return (NBYTES);
}

#include <stdio.h>

int	main()
{
	// char	c 	= 'W';
	// char	*s 	= "bou";
	
	// ft_printf("1: Hello World!\n");
	ft_printf("2: Hello %car-rie\n");
	return (0);
}
