/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:37:14 by lrandria          #+#    #+#             */
/*   Updated: 2021/07/08 23:47:16 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>

# define	FLAGS	" -0.#+"
# define	TYPE	"cspdiuxX%"
# define	NUM		"0123456789"

typedef struct s_flags
{
	bool	add_space : 1;
	bool	left_side : 1;
	bool	leading_zeros : 1;
	bool	precision : 1;
	bool	zero_x : 1;
	bool	sign : 1;
	bool	width : 1;
}			t_flags;

typedef struct s_type
{
	bool	c : 1;
	bool	s : 1;
	bool	p : 1;
	bool	d_i : 1;
	bool	u : 1;
	bool	x_X : 1;
}			t_type;

size_t	ft_putstrsize(const char *s);
int		ft_printf(const char *format, ...);

#endif
