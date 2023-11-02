/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:53:56 by pviegas-          #+#    #+#             */
/*   Updated: 2023/08/09 16:13:39 by pviegas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}

static int	valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base == (void *)0 || base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0') 
	{
		if (base[i] < 32 || base[i] > 126 || base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static long	is_negative(long nbr, int *count)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
        (*count)++;
	}
	return (nbr);
}

int	ft_putnbr_base(int nbr, char *base)
{
	long	length;
	long	j;
	long	l;
	char	k[32];
    int count;

	l = nbr;
	j = 0;
    count = 0;
	length = ft_strlen(base);
	if (valid_base(base) == 0)
		return 0;
	if (l < 0)
		l = is_negative(l, &count);
	while (l >= length)
	{
		k[j++] = base[l % length];
		l = l / length;
	}
	k[j] = base[l];
	while (j >= 0)
	{
		ft_putchar(k[j]);
		j--;
        count++;
	}
    return (count);
}
/*
int main() {
	ft_putnbr_base(2147483647, "01");
	ft_putchar('\n');
	ft_putnbr_base(-2147483648, "01");
	ft_putchar('\n');
	ft_putnbr_base(2147483647, "0123456789");
	ft_putchar('\n');
	ft_putnbr_base(-2147483648, "0123456789");
	ft_putchar('\n');
	ft_putnbr_base(2147483647, "poneyvif");
	ft_putchar('\n');
	ft_putnbr_base(-2147483648, "poneyvif");
	ft_putchar('\n');
	ft_putnbr_base(2147483647, "0123456789ABCDEF");
	ft_putchar('\n');
	ft_putnbr_base(-2147483648, "0123456789ABCDEF");
	ft_putchar('\n');

	return (0);
}*/

