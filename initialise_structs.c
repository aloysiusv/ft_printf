/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_structs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 21:00:59 by lrandria          #+#    #+#             */
/*   Updated: 2021/07/08 22:45:06 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialise_structs(t_flags *flags, t_type *type)
{	
	flags->add_space = FALSE;
	flags->left_side = FALSE;
	flags->leading_zeros = FALSE;
	flags->precision = FALSE;
	flags->zero_x = FALSE;
	flags->sign = FALSE;
	flags->width = FALSE;
	
	type->c = FALSE;
	type->s = FALSE;
	type->p = FALSE;
	type->d_i = FALSE;
	type->u = FALSE;
	type->x_X = FALSE;
	
	return ;
}
