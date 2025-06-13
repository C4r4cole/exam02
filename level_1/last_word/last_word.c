/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:38:33 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/13 11:55:39 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	last_word(char *str)
{
	int	len;

	len = ft_strlen(str);
	while (str[len] != 32 && str[len] != 9)
		len--;
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}	
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		last_word(argv[1]);
	}
	return (0);
}