/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 23:04:15 by lrandria          #+#    #+#             */
/*   Updated: 2021/07/08 23:47:51 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	which_flags(const char *sub_format, char c, va_list lst, t_flags *flags)
{
	size_t	nbytes;
	
	nbytes = 0;
	if (c == ' ')
		flags->add_space = TRUE;
		nbytes++;
	else if (c == '-')
		flags->left_side = TRUE;
		nbytes++;
	else if (c == '0') // PROBLEM
		flags->leading_zeros = TRUE;
		nbytes++;
	else if (c == '.')
		flags->precision = TRUE;
		nbytes++;
	else if (c == '#')
		flags->zero_x = TRUE;
		nbytes = nbytes + 2;
	else if (c == '+')
		flags->sign = TRUE;
		nbytes++;
	else if (c == NUM) // PROBLEM
		
	return (nbytes);
}