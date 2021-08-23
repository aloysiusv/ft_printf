/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:16:16 by lrandria          #+#    #+#             */
/*   Updated: 2021/08/09 19:54:42 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	reset_type(t_info *t)
{
	TYPE = '\0';
}

void	init_info(t_info *t)
{
	TYPE = '\0';
	NBYTES = 0;
}

size_t	do_your_magic(const char *str, t_info *t, va_list ap)
{
	size_t	i;

	i = 0;
	init_info(t);
	while (str[i])
	{
		if (str[i] == '%')
		{
			reset_type(t);
			i++;
			TYPE = str[i];
			if (TYPE == '%')
				NBYTES += write(1, "%", 1);
			else if (if_symbol("cspdiuxX", TYPE) == TRUE)
				go_to_conversion(t, ap);
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

// #include <stdio.h>
// #include "limits.h"

// int	main()
// {
// 	char	*str 	= NULL;
	
// 	printf("");
// 	ft_printf("");
// 	printf("Real: Hello World!\n");
// 	ft_printf("Mine: Hello World!\n");
// 	printf("Real: %c\n", 'Z');
// 	ft_printf("Mine: %c\n", 'Z');
// 	printf("Real: %c, %s\n", 'A', "hoy");
// 	ft_printf("Mine: %c, %s\n", 'A', "hoy");
// 	printf("Real: STR = %s\nReal: PTR = %p\n", str, str);
// 	ft_printf("Mine: STR = %s\nMine: PTR = %p\n", str, str);
// 	printf("Real: %d, %i\n", INT_MIN, 2147483648);
// 	ft_printf("Mine: %d, %i\n", INT_MIN, 2147483648);
// 	printf("Real: %u, %u, %u\n", 0, 346983, 2147483648);
// 	ft_printf("Mine: %u, %u, %u\n", 0, 346983, 2147483648);
// 	printf("Real: %x, %X, %x\n", 0, 346983, 2147483648);
// 	ft_printf("Mine: %x, %X, %x\n", 0, 346983, 2147483648);
// 	printf("Real: %%, %%\n");
// 	ft_printf("Mine: %%, %%\n");

// 	return (0);
// }
