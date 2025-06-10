/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:38:34 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/10 15:15:34 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rotone(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'Z')
			write(1, "A", 1);
		if (str[i] == 'z')
			write(1, "a", 1);
		if (str[i] >= 'A' && str[i] < 'Z')
		{
			c = str[i] + 1;
			write(1, &c, 1);
		}
		else if (str[i] >= 'a' && str[i] < 'z')
		{
			c = str[i] + 1;
			write(1, &c, 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2 || argv[1][0] == '\0')
		write(1, "\n", 1);
	else
	{
		rotone(argv[1]);
		write(1, "\n", 1);
	}
	return (0);
}