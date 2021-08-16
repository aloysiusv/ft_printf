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

# define	FALSE		0
# define	TRUE		1

# define	TYPE		t->type
# define	NBYTES		t->nbytes

typedef struct s_info
{
	char		type;
	size_t		nbytes;
}				t_info;

int				ft_printf(const char *format, ...);
size_t			do_your_magic(const char *str, t_info *t, va_list ap);
void			init_info(t_info *t);
void			go_to_conversion(t_info *t, va_list ap);

size_t			ft_strlen(const char *s);
unsigned int	if_symbol(const char *s, char c);
void			ull_putnbrbase(t_info *t, unsigned long long nb, 
				char *str, size_t base);
void			int_putnbrbase(t_info *t, long nb, char *str, int base);
#endif
