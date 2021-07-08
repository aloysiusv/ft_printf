/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:16:16 by lrandria          #+#    #+#             */
/*   Updated: 2021/07/08 22:50:50 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}

size_t	ft_putstrlen(const char *s)
{
	size_t	nbytes;
	
	if (s == 0)
		return (0);
	nbytes = 0;
	while (s[nbytes])
	{
		write(1, &s[nbytes], 1);
		nbytes++;	
	}
	return (nbytes);
}

int ft_printf(const char *format, ...)
{
	va_list		my_list;
	size_t		nbytes;
	
	nbytes = 0;
	// i = 0;
	if (format == NULL)
		return (-1);
	if (ft_strchr(format, '%') == 0)
		nbytes = ft_putstrlen(format);
	else
		va_start(my_list, format);
		// nbytes = parse_format(format, my_list);
		va_end(my_list);
	return (nbytes);
}

#include <stdio.h>

int	main(void)
{
	// char	c 	= 'K';
	// char	*s 	= "bou";
	
	// ft_printf("1: Hello World!\n");
	// ft_printf("2: Hello World%%%%%!\n");
	// ft_printf("3: Hello %%%%% world!\n");
	// printf("Real: Hello World!\n");
	// printf("Real: Hello %c",);
	// ft_printf("Mine: %s\n", c);
	// printf("Original: %s\n", c);
	// ft_printf("Mine: %s\n", s);
	// printf("Original: %s\n", s);
	int	nbytes = 0;
	int	test = 123;
	char	*s = "douze ans";
	nbytes = printf("HELLO\n%+d\nj'ai %s\n", test, s);
	printf("%d", nbytes);
	return (0);
}