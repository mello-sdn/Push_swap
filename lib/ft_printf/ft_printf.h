#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_print
{
	va_list	args;
	int		len;
}		t_print;

void	ft_putbase10(unsigned int i, t_print *tab);
void	ft_puthexmin(unsigned int i, t_print *tab);
void	ft_puthexmaj(unsigned int i, t_print *tab);
void	ft_putptr_hexa(unsigned long int i, t_print *tab);

int		ft_parse_char(const char *str, int i, t_print *tab);
int		ft_printf(const char *str, ...);
void	is_pointer(t_print *tab);
void	is_hexamin(t_print *tab);
void	is_hexamaj(t_print *tab);
void	is_char(t_print *tab);
void	is_int(t_print *tab);

void	is_string(t_print *tab);
char	*ft_strchr(const char *str, int c);

void	ft_putchar(char c);
void	ft_putnbr(long int nb);
void	ft_putstr(char *str);
void	is_unsigned(t_print *tab);
void	is_sign(t_print *tab);

#endif
