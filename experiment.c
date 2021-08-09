#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int i = 0;
	char *t = "bberco";
	
	while (t[i] != 'r')
	{
		write(1, &t[i], 1);
		i++;
	}
	return (0);
}