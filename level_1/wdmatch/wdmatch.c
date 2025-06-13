/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:37:33 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/13 16:36:14 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	wdmatch(char *s1, char *s2)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (s1[i])
	{
		while(s2[j] && s2[j] != s1[i])
			j++;
		if (!s2[j])
		{
			write(1, "\n", 1);
			return ;
		}
		j++;	
		i++;
	}
	i = 0;
	while (s1[i])
	{
		write(1, &s1[i], 1);
		i++;	
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		write(1, "\n", 1);
	else
	{
		wdmatch(argv[1], argv[2]);
	}
	return (0);
}