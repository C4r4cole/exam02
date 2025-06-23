/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:45:16 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/23 10:55:00 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc != 3)
		printf("\n");
	else
	{
		int	a;
		int b;
		int tmp;

		a = atoi(argv[1]);
		b = atoi(argv[2]);
		while (b != 0)
		{
			tmp = b;
			b = a % b;
			a = tmp;
		}
		printf("%d", a);
	}
}