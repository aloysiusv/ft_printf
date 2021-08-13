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

void	print_conversion(t_info *t, va_list ap)
{
	int		c;

	c = 0;
	if (TYPE == 'c')
	{
		c = (int)va_arg(ap, int);
		NBYTES += write(1, &c, 1);
	}
}

unsigned int	store_type(t_info *t, size_t i)
{
	if (i == 'c')
		TYPE = 'c';
	if (i == 's')
		TYPE = 's';
	if (i == 'p')
		TYPE = 'p';
	if (i == 'd')
		TYPE = 'd';
	if (i == 'i')
		TYPE = 'i';
	if (i == 'u')
		TYPE = 'u';
	if (i == 'x')
		TYPE = 'x';
	if (i == 'X')
		TYPE = 'X';
	if (i == '%')
		TYPE = '%';
	else
		return (FALSE);
	return(TRUE);
}

void	init_info(t_info *t)
{
	SPACE = FALSE;
	DASH = FALSE;
	ZERO_PAD = FALSE;
	IF_PREC = FALSE;
	HASH = FALSE;
	PLUS = FALSE;
	TYPE = '\0';
	START = 0;
	END = 0;
	WIDTH = 0;
	PREC = 0;
	NBYTES = 0;
}

size_t	do_your_magic(const char *str, t_info *t, va_list ap)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			init_info(t);
			END = i;
			while (str[END++])
			{
				if (if_symbol(ALLTYPES, END) == TRUE && store_type(t, END) == TRUE)
					{
						// analyse_conversion(t);
						print_conversion(t, ap);
						i++;
						break ;
					}
				// }
				// if (if_symbol(ALLFLAGS, END) == TRUE)
				// {
				// 	store_flags(t, END);
				// 	if ((is_valid_flags(t)) == FALSE)
				// 		return (-1);
				// }
			}
		}
		else
			NBYTES += write(1, &str[i], 1);
		i++;
	}
	return (NBYTES);
}

int ft_printf(const char *format, ...)
{
	va_list		ap;
	t_info	t[1];
	if (format == NULL)
		return (-1);
	else
	va_start(ap, format);
	NBYTES = do_your_magic(format, t, ap);
	va_end(ap);
	return (NBYTES);
}

#include <stdio.h>

int	main()
{
	char	z = 'Z';
	// char	*s 	= "bou";
	
	ft_printf("1: Hello World!\n");
	ft_printf("2: Hello %c'Brien!\n", z);
	return (0);
}
