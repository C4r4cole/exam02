/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:17:38 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/13 11:36:13 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_power_of_2(unsigned int n)
{
	unsigned int	power;

	power = 1;

	while (power < n)
		power = power * 2;
	if (power == n)
		return (1);
	else
		return (0);
}
// #include <stdlib.h>
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		printf("%d", is_power_of_2(atoi(argv[1])));
// 	}
// 	return (0);
// }