/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:47:12 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/16 14:58:36 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int sign;
	int nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == 9 || str[i] == 10 || str[i] == 11 || str[i] == 12 || str[i] == 13 || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign = sign * -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb *10 + (str[i] - 48);
		i++;
	}
	return (sign * nb);
}

void ft_putnbr(int nb)
{
	long nbr;
	
	nbr = nb;
	if (nbr < 0)
		ft_putchar('-');
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
	}
	ft_putchar((nbr % 10) + '0');
}
int	is_prime(int nb)
{
	int	i;
	
	if (nb < 2)
		return (0);
	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	add_prime_sum(int nb)
{
	int	i;
	int res;

	i = 2;
	res = 0;
	while(i <= nb)
	{
		if (is_prime(i))
		{
			res = res + i;
		}
		i++;
	}
	return (res);
}

int main(int argc, char **argv)
{
	if (argc != 2 || ft_atoi(argv[1]) < 0)
	{
		ft_putchar(0);
		ft_putchar('\n');
	}
	else
	{
		int	res;
		
		res = add_prime_sum(ft_atoi(argv[1]));
		ft_putnbr(res);
	}
	return (0);
}