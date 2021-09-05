/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_bitwise.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:32:07 by lrandria          #+#    #+#             */
/*   Updated: 2021/08/22 21:32:07 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define SPACE 		0b1
# define DASH		0b10
# define ZERO_PAD	0b100
# define DOT		0b1000
# define HASH		0b10000
# define PLUS		0b100000

typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

typedef struct s_info
{
	unsigned int		flags;
	char				type;
	int					prec;
	int					width;
	size_t				nbytes;
	size_t				pos;
}				t_info;

int				ft_printf(const char *format, ...);
void			analyse_conversion(t_info *t, const char *str, va_list ap);
void			print_c(t_info *t, va_list ap);
void			print_s(t_info *t, va_list ap);
void			print_p(t_info *t, va_list ap);
void			print_di(t_info *t, va_list ap);
void			print_u(t_info *t, va_list ap);
void			print_hex(t_info *t, va_list ap, char *base);
void			print_percent(t_info *t);

size_t			ft_strlen(const char *s);
size_t			ft_atoui(const char *str);
t_bool			if_symbol(const char *s, char c);
void			adjust_len(t_info *t, int *len, int init_len, long di);

t_bool			print_nothing(t_info *t, long di);
void			print_extras(t_info *t, int init_len, long di);
void			print_signs(t_info *t, long di);
void			print_padding(t_info *t, int len, int init_len);
void			print_width(t_info *t, int len, long di, unsigned int x);

size_t			ft_ulllen_base(unsigned long long n, size_t base_len);
size_t			ft_intlen_base(int n, size_t base_len);
void			ull_putnbrbase(t_info *t, unsigned long long nb,
					char *str, size_t base);
void			long_putnbrbase(t_info *t, int nb, char *str, long base);

#endif