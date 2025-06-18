/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:35:43 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/18 12:59:06 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	nbr;
	
	nbr = nb;
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
}

void	fprime(char *n)
{
	int	nbr;
	int	i;

	nbr = atoi(n);
	i = 2;
	if (nbr <= 0)
	{
		write(1, "\n", 1);
		return ;
	}
	if (nbr == 1)
	{
		write(1, "1\n", 2);
		return ;
	}
	else
	{
		while (i <= nbr)
		{
			if (nbr % i == 0)
			{
				ft_putnbr(i);
				nbr = nbr / i;
				if (nbr != 1)
					write(1, "*", 1);
			}
			else
				i++;
		}
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		fprime(argv[1]);
	}
	else
		write(1, "\n", 1);
}