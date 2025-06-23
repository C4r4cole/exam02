/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:19:46 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/23 10:43:16 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long nb;
	
	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -n;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar((nb % 10) + 48);
		
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		write(1, "0\n", 2);
	}
	else
	{
		int		i;
		char	*last;
		
		i = 0;
		while (i < argc)
		{
			last = argv[i];
			i++;
		}
		
		ft_putnbr(argc - 1);
		write(1, "\n", 1);
	}
}