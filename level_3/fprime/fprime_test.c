/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:01:36 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/18 14:00:41 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		write(1, "\n", 1);
	else
	{
		
		int	n;
		int i;
		
		n = atoi(argv[1]);
		i = 2;
		if (n == 1)
		{
			write(1, "1", 1);
			return (0);
		}
		while (i <= n)
		{
			if (n % i == 0)
			{
				printf("%d", i);
				n = n / i;
				if (n != 1)
				printf("*");
			}
			else
			i++;
		}
		printf("\n");
	}
}
	