#include "ft_printf.h"

void	is_pointer(t_print *tab)
{
	unsigned long	res;

	res = va_arg(tab->args, unsigned long);
	if (res == 0)
	{
		ft_putstr("(nil)");
		tab->len += 5;
		return ;
	}
	ft_putstr("0x");
	tab->len += 2;
	ft_putptr_hexa(res, tab);
}

void	is_hexamin(t_print *tab)
{
	int	res;

	res = va_arg(tab->args, unsigned int);
	ft_puthexmin(res, tab);
}

void	is_hexamaj(t_print *tab)
{
	int	res;

	res = va_arg(tab->args, unsigned int);
	ft_puthexmaj(res, tab);
}
