/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:52:22 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/13 15:30:51 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	unions(char *s1, char *s2)
{
	int	i;
	int	seen[256] = {0};

	i = 0;
	while (s1[i])
	{
		if (seen[(int)s1[i]] == 0)
		{
			write(1, &s1[i], 1);
			seen[(int)s1[i]] = 1;
		}
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (seen[(int)s2[i]] == 0)
		{
			write(1, &s2[i], 1);
			seen[(int)s2[i]] = 1;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
	}
	else
	{
		unions(argv[1], argv[2]);
		write(1, "\n", 1);
	}
	return (0);
}