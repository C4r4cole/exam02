/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:09:06 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/17 13:39:51 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	epur_str(char *str)
{
	int	i;
	int	started;

	i = 0;
	started = 0;
	while (str[i] == ' ' || str[i] == '\t')
			i++;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			if (started)
				write(1, " ", 1);
			while (str[i] && str[i] != ' ' & str[i] != '\t')
			{
				write(1, &str[i], 1);
				i++;
			}
			started = 1;
		}
		while (str[i] == ' ' || str[i] == '\t')
			i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		epur_str(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}