/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:09:30 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/09 16:47:38 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	first_word(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] == 9 || str[i] == 10 || str[i] == 11 || str[i] == 12 || str[i] == 13 || str[i] == 32)
		i++;
	while (str[i] && str[i] != 32)
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		write(1, "\n", 1);
	else
	{
		first_word(argv[1]);
	}
	return (0);
}