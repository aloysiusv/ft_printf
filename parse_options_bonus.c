/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 14:42:53 by lrandria          #+#    #+#             */
/*   Updated: 2021/08/22 14:42:53 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	go_to_conversion(t_info *t, const char *str, va_list ap)
{
	TYPE = str[POS];
	
	if (TYPE == 'c')
		print_c(t, ap);
	if (TYPE == 's')
		print_s(t, ap);
	if (TYPE == 'p')
		print_p(t, ap);
	if (TYPE == 'd' || TYPE == 'i')
		print_di(t, ap);
	if (TYPE == 'u')
		print_u(t, ap);
	if (TYPE == 'x')
		print_xX(t, ap, "0x", "0123456789abcdef");
	if (TYPE == 'X')
		print_xX(t, ap, "0X", "0123456789ABCDEF");
	if (TYPE == '%')
		print_percent(t);
}

void	store_flags(t_info *t, const char *str)
{
	if (str[POS] == ' ' && PLUS == FALSE)
		SPACE = TRUE;
	else if (str[POS] == '-')
	{
		DASH = TRUE;
		ZERO_PAD = FALSE;
	}
	else if (str[POS] == '0' && DASH == FALSE && DOT == FALSE)
		ZERO_PAD = TRUE;
	else if (str[POS] == '#')
		HASH = TRUE;
	else if (str[POS] == '+')
	{
		PLUS = TRUE;
		SPACE = FALSE;
	}
	POS++;
}

void	store_width(t_info *t, const char *str)
{
	char 	*width_ascii;
	size_t	len;
	size_t	j;
	size_t	k;

	len = 0;
	j = POS;
	while (if_symbol("cspdiuxX%", str[j]) == FALSE)
	{
		if (str[j] >= '0' && str[j] <= '9')
			len++;
		j++;
	}
	width_ascii = (char *)malloc(sizeof(char) * len + 1);
	if (width_ascii == NULL)
		return ;
	k = 0;
	while (str[POS] >= '0' && str[POS] <= '9')
		width_ascii[k++] = str[POS++];
	width_ascii[k] = '\0';
	WIDTH = ft_atoui((const char *)width_ascii);
	free(width_ascii);
}

void	store_precision(t_info *t, const char *str)
{
	char 	*precision_ascii;
	size_t	len;
	size_t	j;
	size_t	k;

	DOT = TRUE;
	ZERO_PAD = FALSE;
	len = 0;
	j = POS;
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
	POS++;
	while (str[POS] >= '0' && str[POS] <= '9')
		precision_ascii[k++] = str[POS++];
	precision_ascii[k] = '\0';
	PREC = ft_atoui((const char *)precision_ascii);
	free(precision_ascii);
}

void	analyse_conversion(t_info *t, const char *str, va_list ap)
{
	POS = POS + 1;
	while (if_symbol(" -0#+", str[POS]) == TRUE)
		store_flags(t, str);
	while (str[POS] >= '1' && str[POS] <= '9')
		store_width(t, str);
	if (str[POS] == '.')
		store_precision(t, str);
	if (if_symbol("cspdiuxX%", str[POS]) == TRUE)
		go_to_conversion(t, str, ap);
}
