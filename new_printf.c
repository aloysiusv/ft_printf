#include "ft_printf.h"

size_t	parse_infos(char *format, t_info *info, size_t start)
{
	size_t	nbytes;
	size_t	i;

	nbytes = 0;
	i = 0;
	while (format[start] != TYPE)
	{
		fill_info(info)
	} 

	nbytes = info->nbytes;
	return (nbytes);
}

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
// 	return (0);
// }

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

int	ft_printf(const char *format, ...)
{
	size_t	nbytes;
	size_t	start;
	t_info	*info;

	nbytes = 0;
	start = 0;
	if (format == NULL)
		return (-1);
	start = ft_strchr(format, '%');
	if (start == 0)
		write(1, format, ft_strlen(format));
	else
		nbytes = parse_infos((char *)format, info, start);
	return (nbytes);
}

