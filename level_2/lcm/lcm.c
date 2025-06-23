/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 09:26:17 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/23 09:42:16 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	gcd(unsigned int a, unsigned int b)
{
	unsigned int tmp;
	while (b != 0)
	{
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return (a);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return (0);
	return ((a / gcd(a, b)) * b);
}

// #include <stdio.h>

// int main(void)
// {
//     printf("lcm(3, 5) = %u\n", lcm(3, 5));     // 15
//     printf("lcm(4, 6) = %u\n", lcm(4, 6));     // 12
//     printf("lcm(0, 2) = %u\n", lcm(0, 2));     // 0
//     return 0;
// }
