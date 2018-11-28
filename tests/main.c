
#include "libft.h"
#include "ft_printf.h"

int     main(void)
{
	//ft_printf("Hello %s - %-20.d!\n", "there!", 25);

	ft_printf("%s %d %s\n", "Hello ", 42, "!");
	//system("leaks a.out");
	return (0);
}
