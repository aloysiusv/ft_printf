#include <stdio.h>
#include "ft_printf_bonus.h"

// size_t	ft_atouint(const char *str)
// {
// 	size_t	i;
// 	size_t	res;

// 	i = 0;
// 	res = 0;
// 	while (str[i] && str[i] >= '0' && str[i] <= '9')
// 	{
// 		res = (res * 10) + (str[i] - '0');
// 		i++;
// 	}
// 	return (res);
// }

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	res = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0') * sign;
		i++;
	}
	return (res);
}

void	width(char *f, size_t *i, t_info *t)
{
	char	*ptr;

	ptr = f;
	while (f[*i] != '\0' && (f[*i] > 47 && f[*i] < 58))
	{
			ptr += *i;
			WIDTH = ft_atoi(ptr);
			while (f[*i] > 47 && f[*i] < 58)
				*i += 1;
	}
	*i += 1;
}
int main(void)
{
	t_info	t[1];
	char str[10] = "HELL123";
	size_t	*i = 0;
	while (str[*i])
	{
		if (str[*i] >= '0' && str[*i] <= '9')
		{
			width(str, i, t);
			break ;
		}
		i++;
	}
	printf("Width = [%zu]", WIDTH);
	return (0);
}