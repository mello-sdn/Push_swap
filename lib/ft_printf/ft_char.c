#include "ft_printf.h"

void	is_char(t_print *tab)
{
	char	res;

	res = va_arg(tab->args, int);
	tab->len += 1;
	ft_putchar(res);
}

void	is_string(t_print *tab)
{
	char	*res;
	int		i;

	res = va_arg(tab->args, char *);
	if (res == NULL)
	{
		ft_putstr("(null)");
		tab->len += 6;
		return ;
	}
	i = 0;
	while (res[i])
	{
		ft_putchar(res[i]);
		tab->len++;
		i++;
	}
}
