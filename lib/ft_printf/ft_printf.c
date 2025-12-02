#include "ft_printf.h"

t_print	*ft_initialise_tab(t_print *tab)
{
	tab->len = 0;
	return (tab);
}

void	ft_conv(char c, t_print *tab)
{
	if (c == 'c')
		is_char(tab);
	else if (c == 's')
		is_string(tab);
	else if (c == 'p')
		is_pointer(tab);
	else if (c == 'd' || c == 'i')
		is_int(tab);
	else if (c == 'u')
		is_unsigned(tab);
	else if (c == 'X')
		is_hexamaj(tab);
	else if (c == 'x')
		is_hexamin(tab);
	else if (c == '%')
		is_sign(tab);
}

int	ft_parse_char(const char *str, int i, t_print *tab)
{
	if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
	{
		ft_conv(str[i + 1], tab);
		return (i + 2);
	}
	ft_putchar(str[i]);
	tab->len++;
	return (i + 1);
}

int	ft_printf(const char *str, ...)
{
	t_print	*tab;
	int		i;
	int		ret;

	if (!str)
		return (-1);
	tab = malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	tab = ft_initialise_tab(tab);
	va_start(tab->args, str);
	i = 0;
	while (str[i])
		i = ft_parse_char(str, i, tab);
	va_end(tab->args);
	ret = tab->len;
	free(tab);
	return (ret);
}

/*
#include <limits.h>
int main(void)
{
	char	*str = NULL;
	char	str2[] = "jai pas d'inspi";
    int ret;

	// Si chaine est vide
	ret = ft_printf("%s\n", str);
    ft_printf("a ecrit %d caracteres\n\n", ret);

	// Si char vide
	ret = ft_printf("%c\n");
    ft_printf("a ecrit %d caracteres\n\n", ret);

    // Chaîne de charactere 
    ret = ft_printf("%s\n", str2); 
	ft_printf("a ecrit %d caracteres\n\n", ret);

	// entier
    ret = ft_printf("%d\n", 42);
    ft_printf("a ecrit %d caracteres\n\n", ret);

    // Hexa minuscule / majuscule et adresse NULL 
    ft_printf("0xff = %#x, 0XFF = %#X\n", 255, 255);
    ft_printf("NULL ptr = %p\n\n", NULL);

    //Limites d’entiers 
    ft_printf("INT_MIN  = %d\nINT_MAX  = %d\nUINT_MAX = %u\n\n",
              INT_MIN, INT_MAX, UINT_MAX);

    // %% et caractère
    ft_printf("Pourcentage : %% et lettre %c\n", 'A');

    return 0;
}
*/