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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

unsigned int	if_symbol(const char *s, char c)
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

void	ull_putnbrbase(t_info *t, unsigned long long nb, char *str, size_t base)
{
	unsigned long long	lol;

	lol = nb;
	if (lol >= base)
		ull_putnbrbase(t, lol / base, str, base);
	NBYTES += write(1, &str[lol % base], 1);
}

void	int_putnbrbase(t_info *t, long nb, char *str, int base)
{
	long	lol;

	if (nb >= 0)
		lol = nb;
	else
	{
		lol = -nb;
		NBYTES += write(1, "-", 1);
	}
	if (lol >= base)
		int_putnbrbase(t, lol / base, str, base);
	NBYTES += write(1, &str[lol % base], 1);
}

void	print_c_or_percent(t_info *t, va_list ap)
{
	char	c;

	if (TYPE == '%')
		NBYTES += write(1, "%", 1);
	else
	{
		c = 0;
		c = (char)va_arg(ap, int);
		NBYTES += write(1, &c, 1);
	}
}

void	print_s(t_info *t, va_list ap)
{
	size_t	i;
	char	*s;

	i = 0;
	s = va_arg(ap, char *);
	if (s == NULL)
		NBYTES += write(1, "(null)", 6);
	else
		while (s[i])
			NBYTES += write(1, &s[i++], 1);
}

void	print_p(t_info *t, va_list ap)
{
	unsigned long long	p;

	p = va_arg(ap, unsigned long long);
	if (!p)
		NBYTES += write(1, "(nil)", 5);
	else
	{
		NBYTES += write(1, "0x", 2);
		ull_putnbrbase(t, p, "0123456789abcedf", 16);
	}
}

void	print_di(t_info *t, va_list ap)
{
	int	di;

	di = va_arg(ap, int);
	int_putnbrbase(t, di, "0123456789", 10);
}

void	print_u(t_info *t, va_list ap)
{
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	ull_putnbrbase(t, u, "0123456789", 10);
}

void	print_xX(t_info *t, va_list ap)
{
	unsigned int x;

	x = va_arg(ap, unsigned int);
	if (TYPE == 'x')
		ull_putnbrbase(t, x, "0123456789abcedf", 16);
	else
		ull_putnbrbase(t, x, "0123456789ABCDEF", 16);
}

void	go_to_conversion(t_info *t, va_list ap)
{
	if (TYPE == 'c' || TYPE == '%')
		print_c_or_percent(t, ap);
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
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			init_info(t);
			TYPE = str[i];
			if (if_symbol("cspdiuxX%", TYPE) == TRUE)
				go_to_conversion(t, ap);
		}
		else
			NBYTES = write(1, &str[i], 1);
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
	printf("Real: %c\n", 'Z');
	ft_printf("Mine: %c\n", 'Z');
	printf("Real: %c, %s\n", 'A', "hoy");
	ft_printf("Mine: %c, %s\n", 'A', "hoy");
	printf("Real: STR = %s\nReal: PTR = %p\n", str, str);
	ft_printf("Mine: STR = %s\nMine: PTR = %p\n", str, str);
	printf("Real: %d, %i\n", INT_MIN, 2147483648);
	ft_printf("Mine: %d, %i\n", INT_MIN, 2147483648);
	printf("Real: %u, %u, %u\n", 0, 346983, 2147483648);
	ft_printf("Mine: %u, %u, %u\n", 0, 346983, 2147483648);
	printf("Real: %x, %X, %x\n", 0, 346983, 2147483648);
	ft_printf("Mine: %x, %X, %x\n", 0, 346983, 2147483648);
	printf("Real: %%, %%\n");
	ft_printf("Mine: %%, %%\n");

	return (0);
}
