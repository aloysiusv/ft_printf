/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 18:42:25 by lrandria          #+#    #+#             */
/*   Updated: 2021/08/14 18:42:25 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H_BONUS
# define FT_PRINTF_H_BONUS

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define	FALSE		0
# define	TRUE		1

# define	SPACE 		t->space
# define	DASH		t->dash
# define	ZERO_PAD	t->zero_pad
# define	DOT			t->dot
# define	HASH		t->hash
# define	PLUS		t->plus
# define	TYPE		t->type
# define	WIDTH		t->width
# define	PREC		t->prec
# define	NBYTES		t->nbytes

# define	ALLSYMBOLS	" -.#+0123456789cspdiuxX%"
# define	ALLFLAGS	" -.#+0"
# define	ALLTYPES	"cspdiuxX%"	

typedef struct s_info
{
	unsigned int		space 		: 1;	
	unsigned int		dash 		: 1;
	unsigned int		zero_pad 	: 1;
	unsigned int		dot 		: 1;
	unsigned int		hash 		: 1;
	unsigned int		plus 		: 1;
	char				type;
	size_t				width;
	size_t				prec;
	size_t				nbytes;
}				t_info;

int		ft_printf(const char *format, ...);

#endif
