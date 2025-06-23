/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:28:04 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/23 14:48:02 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_letter(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

char to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

char to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

void	str_capitalizer(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (is_letter(str[i]))
			str[i] = to_lower(str[i]);
		if (i == 0 || !(is_letter(str[i - 1])))
			str[i] = to_upper(str[i]);
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		write(1, "\n", 1);
	else
	{
		int	i;
		
		i = 1;
		while (i < argc)
		{
			str_capitalizer(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
}