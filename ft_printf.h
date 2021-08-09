/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:37:14 by lrandria          #+#    #+#             */
/*   Updated: 2021/08/09 19:47:29 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "utils.h"

# define	SPACE 		t->space
# define	DASH		t->dash
# define	ZERO_PAD	t->zero_pad
# define	PREC		t->prec
# define	HASH		t->hash
# define	PLUS		t->plus
# define	TYPE		t->type
# define	START		t->start
# define	END			t->end
# define	WIDTH		t->width
# define	NBYTES		t->nbytes


typedef struct s_info
{
	unsigned int	space: 1;
	unsigned int	dash: 1;
	unsigned int	zero_pad: 1;
	unsigned int	prec: 1;
	unsigned int	hash: 1;
	unsigned int	plus: 1;
	char			type;
	size_t			start;
	size_t			end;
	size_t			width;
	size_t			nbytes;
}			t_info;

int		ft_printf(const char *format, ...);

#endif
