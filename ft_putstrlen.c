/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:40:55 by lrandria          #+#    #+#             */
/*   Updated: 2021/07/08 17:59:14 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_putstrlen(const char *s)
{
	size_t	i;
	
	if (s == 0)
		return (0);
	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
	return (i);
}
