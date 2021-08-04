/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:37:14 by lrandria          #+#    #+#             */
/*   Updated: 2021/08/04 19:23:24 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

# define	FLAGS	" -0.#+"
# define	TYPE	"cspdiuxX%"
# define	NUM		"0123456789"

typedef struct s_info
{
	int	hash;
	int	space;
	int	dash;
	int	zero_pad;
	int	plus;
	int	star;
	int	width;
	int	prec;
	int	nbytes;
}			t_info;

int		ft_printf(const char *format, ...);

#endif
