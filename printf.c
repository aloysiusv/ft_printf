/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:16:05 by lrandria          #+#    #+#             */
/*   Updated: 2021/07/07 19:48:18 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	parse_format(const char *fmt, va_list list)
// {
// 	size_t 	i;
// 	size_t	nbytes;

// 	i = 0;
// 	nbytes = 0;
// 	while (fmt[i])
// 	{
// 		if (fmt[i] == '%')
// 			if (fmt[i + 1] == FLAGS)
// 				parse_flags(fmt, list);
// 			if (fmt[i + 1] == TYPE)
// 				convert_type(fmt, list);
// 		else
// 			ft_putstr(fmt);
// 	}
// 	return (nbytes);
// }

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	ft_putstr_fd(const char *s, int fd)
{
	if (s == 0)
		return ;
	write(fd, s, ft_strlen(s));
}

size_t	ft_putstrlen(const char *s)
{
	size_t	nbytes;
	
	nbytes = ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (nbytes);
}

#include <stdio.h>

int ft_printf(const char *format, ...)
{
	size_t		nbytes;
	va_list		my_list;
	
	nbytes = 0;
	if (format == NULL)
		return (-1);
	if (*format++ != '%')
		nbytes = ft_putstrlen(format);
	va_start(my_list, format);
	// nbytes = parse_format(format, my_list);
	va_end(my_list);
	printf("nbytes = %zu\n", nbytes);
	return (nbytes);
}

#include <stdio.h>

int	main(void)
{
	// char	c 	= 'K';
	// char	*s 	= "bou";
	
	ft_printf("Hello world!\n");
	printf("Hello World!\n");
	// ft_printf("Mine: %s\n", c);
	// printf("Original: %s\n", c);
	// ft_printf("Mine: %s\n", s);
	// printf("Original: %s\n", s);
	return (0);
}