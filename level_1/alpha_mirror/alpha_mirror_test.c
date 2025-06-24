/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:17:59 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/23 16:33:34 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc != 2)
		write(1, "\n", 1);
	else
	{
		int	i;

		i = 0;
		while (argv[1][i])
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				argv[1][i] = 219 - argv[1][i];
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				argv[1][i] = 155 - argv[1][i];
			write(1, &argv[1][i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
}