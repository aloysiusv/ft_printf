/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:16:05 by lrandria          #+#    #+#             */
/*   Updated: 2021/06/29 17:12:44 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <>

cspiduxX%

// typedef struct s_flags{
// 	char	dash;
// 	char	zero;
// 	char	dot;
// 	char	star;
// 	char	hashtag;
// 	char	space;
// 	char	plus;	
// }t_flags

// void	ft_convert_d_i(char *format)
// {
// 	size_t	i;

// 	i = 0;
// 	while (format[i])
// 		if (format[i] == '%' && (format[i + 1] == 'd' || format[i] + 1 == 'i')
			
	
// }

#include <stdarg.h>

int ft_printf(const char *format, ...)
{
	va_list		list_of_arguments;
	size_t		nb_of_chars;
	
	nb_of_chars = 0;
	va_start(list_of_arguments, format);
	
	
	
	va_end(list_of_arguments);
	return (nb_of_chars);
}

int	main(int argc)