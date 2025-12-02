#include "ft_printf.h"

void	is_int(t_print *tab)
{
	long int	nb;
	int			res;

	res = va_arg(tab->args, int);
	nb = res;
	if (nb < 0)
	{
		ft_putchar('-');
		tab->len++;
		nb = -nb;
	}
	ft_putnbr(nb);
	if (nb == 0)
		tab->len++;
	while (nb != 0)
	{
		nb = nb / 10;
		tab->len++;
	}
}

void	is_unsigned(t_print *tab)
{
	int	res;

	res = va_arg(tab->args, unsigned int);
	ft_putbase10(res, tab);
}

void	is_sign(t_print *tab)
{
	ft_putchar('%');
	tab->len++;
}
