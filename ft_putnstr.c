
#include "libft.h"

void	ft_putnstr(char *s, size_t n)
{
	size_t i;

	i = 0;
	while (s[i] && i < n)
	{
		write(1, &s[i], 1);
		i++;
	}
}
