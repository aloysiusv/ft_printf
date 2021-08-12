#include <stdio.h>
#include <unistd.h>

EXAMPLES
"%d and %s!"
"%c"
"hello %s!"
"i have %d"
"i am %i years old, %s"


size_t	ft_strlen(char *str)
{
	size_t 	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
void	analyse_format(const char * format, t_info *t)
{
	size_t	i;

	i = 0;
	while (format[i])
	{
		while (format[i] != '%')
		{
			NBYTES += write(1, &format[i], 1);
			i++;
		}
		else
			START = i + 1;
			fill_info(format, START, t);
			parse_type(format, START, t)
			NBYTES += print_conversion(t)
	}
}

int ft_printf(const char *format, ...)
{
	va_list		ap;
	t_info		t[1];

	va_start(ap, format);
	analyse_format(format, t);
	va_end(ap);
	return (NBYTES);
}

int	main(void)
{
	char *str = "Liana";
	write(1, str, (ft_strlen(str) - 3));
	return (0);
}
