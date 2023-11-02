#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

int ft_putnbr_base_ul(unsigned long long nbr, char *base);
int	ft_base_u(unsigned int nbr, char *base);
int	ft_putnbr_base(int nbr, char *base);
int	ft_printf(const char *str, ...);

#endif
