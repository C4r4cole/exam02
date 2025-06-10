/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:23:11 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/10 20:11:20 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int first_index(char c)
{
	int	i;
	char	*minus_first_13;
	char	*capital_first_13;
	char	*minus_last_13;
	char	*capital_last_13;

	i = 0;
	minus_first_13 = "abcdefghijklm";
	capital_first_13 = "ABCDEFGHIJKLM";
	minus_last_13 = "zyxwvutsrqpon";
	capital_last_13 = "ZYXWVUTSRQPON";
	
	if (c >= 'a' && c <= 'm')
	{
		while (c != minus_first_13[i])
		{
			i++;
		}
	}
	else if (c >= 'A' && c <= 'M')
	{
		while (c != capital_first_13[i])
		{
			i++;
		}
	}
	else if (c >= 'n' && c <= 'z')
	{
		while (c != minus_last_13[i])
		{
			i++;
		}
	}
	else if (c >= 'N' && c <= 'Z')
	{
		while (c != capital_last_13[i])
		{
			i++;
		}
	}
	else
		return (-1);
	return (i);
}

void	alpha_mirror(char *str)
{
	int		i;
	int		first_i;
	char	c;
	char	*minus_first_13;
	char	*capital_first_13;
	char	*minus_last_13;
	char	*capital_last_13;
	
	i = 0;
	minus_first_13 = "abcdefghijklm";
	capital_first_13 = "ABCDEFGHIJKLM";
	minus_last_13 = "zyxwvutsrqpon";
	capital_last_13 = "ZYXWVUTSRQPON";
	while (str[i])
	{
		first_i = first_index(str[i]);
		if (first_i == -1)
			write(1, &str[i], 1);
		else if (str[i] >= 'A' && str[i] <= 'M')
		{
			c = capital_last_13[first_i];
			write(1, &c, 1);
		}
		else if (str[i] >= 'a' && str[i] <= 'm')
		{
			c = minus_last_13[first_i];
			write(1, &c, 1);
		}
		else if (str[i] >= 'N' && str[i] <= 'Z')
		{
			c = capital_first_13[first_i];
			write(1, &c, 1);
		}
		else if (str[i] >= 'n' && str[i] <= 'z')
		{
			c = minus_first_13[first_i];
			write(1, &c, 1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2 || argv[1][0] == '\0')
		write(1, "\n", 1);
	else
	{
		alpha_mirror(argv[1]);
	}
	return (0);
}