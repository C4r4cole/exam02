/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 08:57:39 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/23 09:22:51 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_hidden(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		while (s2[j] && s1[i] != s2[j])
			j++;
		if (s2[j] == '\0')
			return (0);
		j++;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		write(1, "\n", 1);
	else
	{
		int	hidenp;
		
		hidenp = is_hidden(argv[1], argv[2]);
		if (hidenp == 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		write(1, "\n", 1);
	}
}