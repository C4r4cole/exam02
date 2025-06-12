/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:08:51 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/12 14:53:57 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	inter(char *s1, char *s2)
{
	int	i;
	int	j;
	int seen[256] = {0};

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
			{
				if (seen[(unsigned char)s1[i]] == 0)
				{
					write(1, &s1[i], 1);
					seen[(unsigned char)s1[i]] = 1;
				}
				break;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		write(1, "\n", 1);
	else
	{
		inter(argv[1], argv[2]);
		write(1, "\n", 1);
	}
}