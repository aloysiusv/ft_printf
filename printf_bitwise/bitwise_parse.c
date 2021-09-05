/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bitwise.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:40:10 by lrandria          #+#    #+#             */
/*   Updated: 2021/08/22 21:40:10 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	go_to_conversion(t_info *t, const char *str, va_list ap)
{
	t->type = str[t->pos];
	if (t->type == 'c')
		print_c(t, ap);
	if (t->type == 's')
		print_s(t, ap);
	if (t->type == 'p')
		print_p(t, ap);
	if (t->type == 'd' || t->type == 'i')
		print_di(t, ap);
	if (t->type == 'u')
		print_u(t, ap);
	if (t->type == 'x')
		print_xX(t, ap, "0123456789abcdef");
	if (t->type == 'X')
		print_xX(t, ap, "0123456789ABCDEF");
	if (t->type == '%')
		print_percent(t);
}

void	store_precision(t_info *t, const char *str)
{
	char	*precision_ascii;
	size_t	len;
	size_t	j;
	size_t	k;

	len = 0;
	j = t->pos;
	j = j + 1;
	while (if_symbol("cspdiuxX%", str[j]) == FALSE)
	{
		if (str[j] >= '0' && str[j] <= '9')
			len++;
		j++;
	}
	precision_ascii = (char *)malloc(sizeof(char) * len + 1);
	if (precision_ascii == NULL)
		return ;
	k = 0;
	t->pos++;
	while (str[t->pos] >= '0' && str[t->pos] <= '9')
		precision_ascii[k++] = str[t->pos++];
	precision_ascii[k] = '\0';
	t->prec = ft_atoui((const char *)precision_ascii);
	free(precision_ascii);
}

void	store_width(t_info *t, const char *str)
{
	char	*width_ascii;
	size_t	len;
	size_t	j;
	size_t	k;

	len = 0;
	j = t->pos;
	while (if_symbol(".cspdiuxX%", str[j]) == FALSE)
	{
		if (str[j] >= '0' && str[j] <= '9')
			len++;
		j++;
	}
	width_ascii = (char *)malloc(sizeof(char) * len + 1);
	if (width_ascii == NULL)
		return ;
	k = 0;
	while (str[t->pos] >= '0' && str[t->pos] <= '9')
		width_ascii[k++] = str[t->pos++];
	width_ascii[k] = '\0';
	t->width = ft_atoui((const char *)width_ascii);
	free(width_ascii);
}

void	store_flags(t_info *t, const char *str)
{
	if (str[t->pos] == ' ' && !(t->flags & PLUS))
		t->flags |= SPACE;
	else if (str[t->pos] == '-')
	{
		t->flags |= DASH;
		t->flags &= ~ZERO_PAD;
	}
	else if (str[t->pos] == '0' && !(t->flags & DASH))
		t->flags |= ZERO_PAD;
	else if (str[t->pos] == '#')
		t->flags |= HASH;
	else if (str[t->pos] == '+')
	{
		t->flags |= PLUS;
		t->flags &= ~SPACE;
	}
	t->pos++;
}

void	analyse_conversion(t_info *t, const char *str, va_list ap)
{
	t->pos = t->pos + 1;
	while (if_symbol(" -0#+", str[t->pos]) == TRUE)
		store_flags(t, str);
	while (str[t->pos] >= '1' && str[t->pos] <= '9')
		store_width(t, str);
	if (str[t->pos] == '.')
	{
		t->flags |= DOT;
		t->flags &= ~ZERO_PAD;
		store_precision(t, str);
	}
	if (if_symbol("cspdiuxX%", str[t->pos]) == TRUE)
		go_to_conversion(t, str, ap);
}
