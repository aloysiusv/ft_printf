/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:07:47 by lrandria          #+#    #+#             */
/*   Updated: 2021/08/10 11:07:47 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

#define	true		1
#define	false		0

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

unsigned int	if_symbol(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (true);
		i++;
	}
	return (false);
}

// int		check_format_error(char *format)
// {
// 	size_t	i;

// 	i = 0;
// 	if (format == NULL)
// 		return (-1);
// 	while (format[i])
// 	{
// 		if (format[i] == '%' && ft_strlen(format) == 1)
// 			return (-1);
// 		if (format[i] == '%' && format[i + 1] == 	
// 			return (-1);
// 		i++;
// 	)
// }

// void	print_else(char *format, size_t start, size_t end)
// {
	
// }