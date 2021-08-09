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

size_t	analyse_format(const char *format, t_info *t)
{
	size_t	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			START = i + 1;
			while (START && !(ft_strchr("cspdiuxX%", START)))
			{
				fill_flags(t)
				START++;
			}
			if (START && ft_strchr("cspdiuxX%", START))
			{
				fill_type(t);
				END = START;
			}
				NBYTES += write(1, &format[i], 1);
	}
	return(NBYTES);
}

void	init_info(t_info *t)
{
	SPACE = 0;
	DASH = 0;
	ZERO_PAD = 0;
	PREC = 0;
	HASH = 0;
	PLUS = 0;
	TYPE = '\0';
	START = 0;
	WIDTH = 0;
	NBYTES = 0;
}

int ft_printf(const char *format, ...)
{
	va_list		ap;
	t_info		t[1];
	
	if (format == NULL)
		return (-1);
	if (ft_strchr(format, '%') == 0)
		NBYTES = write(1, format, ft_strlen(format));
	else
	{
		init_info(t);
		va_start(ap, format);
		analyse_format(format, t);
		va_end(ap);
	}
	return (NBYTES);
}

#include <stdio.h>

int	main(void)
{
	// char	c 	= 'W';
	// char	*s 	= "bou";
	
	// ft_printf("1: Hello World!\n");
	ft_printf("2: Hello %orld\n");
	// printf("Real: Hello %c",);
	// ft_printf("Mine: %s\n", c);
	// printf("Original: %s\n", c);
	// ft_printf("Mine: %s\n", s);
	// printf("Original: %s\n", s);
	// int	nbytes = 0;
	// int	test = 123;
	// char	*s = "douze ans";
	// nbytes = printf("HELLO\n%+d\nj'ai %s\n", test, s);
	// printf("%d", nbytes);
	return (0);
}