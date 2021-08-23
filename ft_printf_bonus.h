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
# define	POS			t->pos

typedef	enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

typedef struct s_info
{
	t_bool				space 		: 1;	
	t_bool				dash 		: 1;
	t_bool				zero_pad 	: 1;
	t_bool				dot 		: 1;
	t_bool				hash 		: 1;
	t_bool				plus 		: 1;
	char				type;
	size_t				width;
	size_t				prec;
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
void			print_xX(t_info *t, va_list ap, char *hash, char *base);
void			print_percent(t_info *t);

size_t			ft_strlen(const char *s);
size_t			ft_atoui(const char *str);
size_t			ft_ulllen_base(unsigned long long n, size_t base_len);
size_t			ft_intlen_base(int n, size_t base_len);
void			ull_putnbrbase(t_info *t, unsigned long long nb, char *str, 
				size_t base);
void			long_putnbrbase(t_info *t, int nb, char *str, long base);
unsigned int	if_symbol(const char *s, char c);

#endif
