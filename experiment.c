#include <stdio.h>
#include <unistd.h>

EXAMPLES
"%d and %s!"
"%c"
"hello %s!"
"i have %d"
"i am %-0i years old, %s"


size_t	ft_strlen(char *str)
{
	size_t 	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int		do_your_magic(const char *str, t_info *t)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			init_info(t);
			START = i;
			END = i + 1;
			while (str[END])
			{
				if (if_symbol(ALLTYPES, END) == TRUE)
					store_type(t);
					if (check_if_error(t) == FALSE)
					{
						NBYTES += print_conversion(t);
						break ;
					}
				if (if_symbol(ALLFLAGS, END) == TRUE)
				{
					store_flags(t)
					END++;
				}
			
		}
		else if (str[i] &&)
		i++;
	}
	return (NBYTES);
}

int ft_printf(const char *format, ...)
{
	va_list		ap;
	t_info		t[1];

	va_start(ap, format);
	do_your_magic(format, t);
	va_end(ap);
	return (NBYTES);
}

int	main(void)
{
	char *str = "Liana";
	write(1, str, (ft_strlen(str) - 3));
	return (0);
}
