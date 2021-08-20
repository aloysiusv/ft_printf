/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 18:40:22 by lrandria          #+#    #+#             */
/*   Updated: 2021/08/14 18:40:22 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	go_to_conversion(t_info *t, va_list ap)
{
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
	if (TYPE == 'x' || TYPE == 'X')
		print_xX(t, ap);
	if (TYPE == '%')
		print_percent(t);
}

void	init_info(t_info *t)
{
	SPACE = FALSE;
	DASH = FALSE;
	ZERO_PAD = FALSE;
	DOT = FALSE;
	HASH = FALSE;
	PLUS = FALSE;
	TYPE = '\0';
	WIDTH = 0;
	PREC = 0;
	NBYTES = 0;
}

size_t	do_your_magic(const char *str, t_info *t, va_list ap)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			init_info(t);
			while (if_symbol(ALLFLAGS, str[i]) == TRUE)
			{
				store_flags(t, str[i]);
				i++;
			}
			while (str[i] >= '1' && str[i] <= '9')
				store_width(t, str, &i);
			if (str[i] == '.') 
			{
				DOT = TRUE;
				ZERO_PAD = FALSE;
				if (str[i + 1] == '0')
					PREC = 0;
				store_precision(t, str, &i);
			}
			if (if_symbol("cspdiuxX%", str[i]) == TRUE)
			{
				TYPE = str[i];
				go_to_conversion(t, ap);
			}
		}
		else
			NBYTES += write(1, &str[i], 1);
		i++;
	}
	return (NBYTES);
}

int ft_printf(const char *format, ...)
{
	va_list		ap;
	t_info	t[1];
	
	va_start(ap, format);
	NBYTES = do_your_magic(format, t, ap);
	va_end(ap);

	return (NBYTES);
}

#include <stdio.h>
#include "limits.h"

int	main()
{
	char	*str 	= NULL;
	
	printf("");
	ft_printf("");
	printf("Real: Hello World!\n");
	ft_printf("Mine: Hello World!\n");
	printf("Real: [%c]\n", 'Z');
	ft_printf("Mine: [%c]\n", 'Z');
	printf("Real: [%c], [%-10s]\n", 'A', "hoy");
	ft_printf("Real: [%c], [%-10s]\n", 'A', "hoy");
	printf("Real: STR = [%s]\nReal: PTR = [%p]\n", str, str);
	ft_printf("Mine: STR = [%s]\nMine: PTR = [%p]\n", str, str);
	printf("Real: [%d], [%i]\n", INT_MIN, 2147483648);
	ft_printf("Mine: [%d], [%i]\n", INT_MIN, 2147483648);
	printf("Real: [%u], [%u], [%u]\n", 0, 346983, 2147483648);
	ft_printf("Mine: [%u], [%u], [%u]\n", 0, 346983, 2147483648);
	printf("Real: [%x], [%X], [%x]\n", 0, 346983, 2147483648);
	ft_printf("Mine: [%x], [%X], [%x]\n", 0, 346983, 2147483648);
	printf("Real: [%%], [%%]\n");
	ft_printf("Mine: [%%], [%%]\n");
	printf("v NOW FOR BONUSES v\n");
	printf("Real: [%-10c]\n", 'K');
	ft_printf("Mine: [%-10c]\n", 'K');
	printf("Real: [%010d]\n", -42);
	ft_printf("Mine: [%010d]\n", 42);
	printf("Real: [%-10d]\n", -42);
	printf("Mine: [%-10d]\n", 42);

	return (0);
}
