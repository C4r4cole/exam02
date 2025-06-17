/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:46:20 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/17 20:18:52 by fmoulin          ###   ########.fr       */
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
	long nbr;

	nbr = nb;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
	}
	ft_putchar((nbr % 10) + 48);
}

int	*ft_range(int start, int end)
{
	int	*tab;
	int	len;
	int	i;

	i = 0;
	len = 0;
	if (start <= end)
		len = end - start + 1;
	else
		len = start - end + 1;
	tab = malloc(sizeof(int) * len);
	if (!tab)
		return (0);
	i = 0;
	if (start <= end)
	{
		while (i < len)
		{
			tab[i] = start + i;
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			tab[i] = start - i;
			i++;
		}
	}
	return(tab);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		int	i;
		int	*tab;
		int	len;
		int start;
		int	end;

		i = 0;
		len = 0;
		start = atoi(argv[1]);
		end = atoi(argv[2]);
		if (start <= end)
			len = end - start +1;
		else
			len = start - end + 1;
		tab = ft_range(start, end);
		if (!tab)
			return (1);
		while (i < len)
		{
			ft_putnbr(tab[i]);
			write(1, ", ", 2);
			i++;
		}
		write(1, "\n", 1);
		free(tab);
	}
}