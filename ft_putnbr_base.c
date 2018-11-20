
#include "libft.h"

void	ft_putnbr_base(intmax_t n, char *base_chars)
{
	int base;

	base = ft_strlen(base_chars);
	if (n < 0 && base == 10)
		ft_putchar('-');
	if (n > base - 1|| n < -base + 1)
		ft_putnbr_base(n < 0 ? -(n / base) : n / base, base_chars);
	ft_putchar(base_chars[ft_abs(n % base)]);
}
