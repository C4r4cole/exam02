/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:59:54 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/23 11:41:06 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == 9 || str[i] == 10 || str[i] == 11 || str[i] == 12 || str[i] == 13 || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (sign * nb);
	
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr_base(int nb)
{
	long	nbr;
	char	*hexa;

	nbr = nb;
	hexa = "0123456789abcdef";
	if (nbr < 0)
		ft_putchar('-');
	if (nbr > 15)
	{
		ft_putnbr_base(nbr / 16);
	}
	ft_putchar(hexa[(nbr % 16)]);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		write(1, "\n", 1);
	else
	{
		int	nbr;

		nbr = ft_atoi(argv[1]);
		ft_putnbr_base(nbr);
	}
}