/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_subformat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:01:41 by lrandria          #+#    #+#             */
/*   Updated: 2021/07/08 23:43:48 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct s_flags
{
	bool	add_space : 1;
	bool	left_side : 1;
	bool	zero_pad : 1;
	bool	precision : 1;
	bool	zero_x : 1;
	bool	sign : 1;
	bool	width : 1;
} 			t_flags;

typedef struct s_type
{
	bool	c : 1;
	bool	s : 1;
	bool	p : 1;
	bool	d_i : 1;
	bool	u : 1;
	bool	x_X : 1;
} 			t_type;

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *)s + i);
// 		i++;
// 	}
// 	if (s[i] == (char)c)
// 		return ((char *)s + i);
// 	return (0);
// }

// size_t	ft_putstrlen(const char *s)
// {
// 	size_t	nbytes;
	
// 	if (s == 0)
// 		return (0);
// 	nbytes = 0;
// 	while (s[nbytes])
// 	{
// 		write(1, &s[nbytes], 1);
// 		nbytes++;	
// 	}
// 	return (nbytes);
// }

int ft_printf(const char *format, ...)
{
	va_list		my_list;
	size_t		nbytes;
	int			if_percent;
	char		*sub_format;
	
	nbytes = 0;
	if (format == NULL)
		return (-1);
	if_percent = ft_strchr(format, '%');
	if (if_percent == 0)
		nbytes = ft_putstrlen(format);
	else
	{
		va_start(my_list, format);
		sub_format = ft_substr(format, if_percent, ft_strlen(format - if_percent));
		if (sub_format == NULL)
			return (-1);
		nbytes = parse_subformat(sub_format, my_list, ft_strlen(format - if_percent));
		va_end(my_list);
	}
	free(sub_format);
	return (nbytes);
}

int	parse_format(const char *sub_format, va_list my_list, size_t nbytes)
{
	size_t			i;
	t_flags			*my_flags;
	t_type			*my_type;
	
	i = 1;
	initialise_structs(&my_flags, &my_type);
	while (sub_format[i])
	{
		if (sub_format[i] == FLAGS)
			which_flags(&sub_format, sub_format[i], my_list, &my_flags);
		if (sub_format[i] == TYPE)
			which_type(sub_format[i], my_list, &my_type);
		else
			write(1, &sub_format[i], 1);
		i++;
	}
	return (nbytes);
}
