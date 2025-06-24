/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:49:10 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/23 17:03:13 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + 48);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		write(1, "\n", 1);
	else
	{
		int	a;
		int	b;
		char	op;
		int res;
		
		res = 0;
		a = atoi(argv[1]);
		op = argv[2][0];
		b = atoi(argv[3]);
		if (op == '+')
			res = a + b;
		else if (op == '-')
			res = a - b;
		else if (op == '*')
			res = a * b;
		else if (op == '/')
			res = a / b;
		else if (op == '%')
			res = a % b;
		ft_putnbr(res);
	}
}