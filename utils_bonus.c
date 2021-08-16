#include "ft_printf_bonus.h"

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

void	store_flags(t_info *t,  char i)
{
	if (i == ' ' && PLUS == FALSE)
		SPACE = TRUE;
	else if (i == '-')
	{
		DASH = TRUE;
		ZERO_PAD = FALSE;
	}
	else if (i == '0' && DASH == FALSE && DOT == FALSE)
		ZERO_PAD = TRUE;
	else if (i == '.')
	{
		DOT = TRUE;
		ZERO_PAD = FALSE;
	}
	else if (i == '#')
		HASH = TRUE;
	else if (i == '+')
	{
		PLUS = TRUE;
		SPACE = FALSE;
	}
}

void	ull_putnbrbase(t_info *t, unsigned long long nb, char *str, size_t base)
{
	unsigned long long	lol;

	lol = nb;
	if (PLUS == TRUE)
		NBYTES += write(1, "+", 1);
	if (lol >= base)
		ull_putnbrbase(t, lol / base, str, base);
	NBYTES += write(1, &str[lol % base], 1);
}

void	int_putnbrbase(t_info *t, long nb, char *str, int base)
{
	long	lol;

	if (nb >= 0)
	{
		if (PLUS == TRUE)
			NBYTES += write(1, "+", 1);
		lol = nb;
	}
	else
	{
		lol = -nb;
		NBYTES += write(1, "-", 1);
	}
	if (lol >= base)
		int_putnbrbase(t, lol / base, str, base);
	NBYTES += write(1, &str[lol % base], 1);
}