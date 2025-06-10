/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:12:32 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/10 17:39:48 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// int	ft_strcmp(char *s1, char *s2)
// {
// 	int	i;
// 	int	res;
	
// 	res = 0;
// 	i = 0;
// 	while(s1[i])
// 	{
// 		res = s1[i] - s2[i];
// 		i++;
// 	}
// 	return (res);
// }

void	search_and_replace(char *str, char *old, char *new)
{
	int	i;
	
	i = 0;
	while (str[i])
	{ 
		if(str[i] == old[0])
			write(1, &new[0], 1);
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		write(1, "\n", 1);
	else
	{
		search_and_replace(argv[1], argv[2], argv[3]);
		write(1, "\n", 1);
	}
	return (0);
}