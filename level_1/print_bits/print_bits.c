/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:33:05 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/13 14:28:42 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (octet >> i) & 1;
		if (bit == 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i--;
	}
}
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	nb;

		nb = atoi(argv[1]);
		print_bits(nb);
	}
	return (0);
}
