/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime_again.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:17:09 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/24 09:34:31 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	 ft_putchar(n % 10 + 48);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		write(1, "\n", 1);
	else
	{
		int	nbr;
		int	i;

		nbr = atoi(argv[1]);
		i = 2;
		if (nbr == 1)
			write(1, "1\n", 2);
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
	}
}