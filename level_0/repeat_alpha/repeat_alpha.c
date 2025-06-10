/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:19:40 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/10 12:06:42 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	repeat_alpha(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str[i] == '\0')
		write(1, "\n", 1);
	while (str[i])
	{
		j = 0;
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			while (j < str[i] - 96)
			{
				write(1, &str[i], 1);
				j++;	
			}
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			while (j < str[i] - 64)
			{
				write(1, &str[i], 1);
				j++;	
			}
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		write(1, "\n", 1);
	else
		repeat_alpha(argv[1]);
	return (0);
}