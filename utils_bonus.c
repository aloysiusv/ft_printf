/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 14:34:49 by lrandria          #+#    #+#             */
/*   Updated: 2021/09/05 14:34:49 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

t_bool	if_symbol(const char *s, char c)

{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

size_t	ft_atoui(const char *str)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res);
}

void	adjust_len(t_info *t, int *len, int init_len, long di)
{
	if ((t->flags & DOT) && t->prec >= init_len)
	{
		if (t->type == 'd' || t->type == 'i')
			if (di < 0)
				t->prec += 1;
		*len = t->prec;
	}
}
