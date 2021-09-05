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

# define FALSE		0
# define TRUE		1

typedef struct s_info
{
	char		type;
	size_t		nbytes;
}				t_info;

int				ft_printf(const char *format, ...);

void			print_c_or_percent(t_info *t, va_list ap);
void			print_s(t_info *t, va_list ap);

void			print_p(t_info *t, va_list ap);
void			print_di(t_info *t, va_list ap);
void			print_u(t_info *t, va_list ap);
void			print_hex(t_info *t, va_list ap);

size_t			ft_strlen(const char *s);
unsigned int	if_symbol(const char *s, char c);
void			int_putnbrbase(t_info *t, long nb, char *str, int base);
void			ull_putnbrbase(t_info *t, unsigned long long nb,
					char *str, size_t base);
#endif
