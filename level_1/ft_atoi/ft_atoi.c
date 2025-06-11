/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:40:13 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/11 16:59:16 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	if (str[i] == 9 || str[i] == 10 || str[i] == 11 || str[i] == 12 || str[i] == 13 || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = sign * -1;
		i++; 
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * sign);
}

// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		printf("%d", ft_atoi(argv[1]));
// 	}
// 	return (0);
// }