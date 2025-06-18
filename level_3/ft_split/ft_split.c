/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:56:20 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/18 16:53:10 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_space(char c)
{
	return (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32);
}

int	count_words(char *str)
{
	int	count;
	int	i;
	
	i = 0;
	count = 0;
	while (str[i])
	{
		if (!is_space(str[i]) && (i == 0 || is_space(str[i - 1])))
			count++;
		i++;
	}
	return (count);
}

char	*word_dup(char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}



char	**ft_split(char *str)
{
	char	**tab;
	int		nbr_words;
	int		i;
	int		j;
	int		start;
	
	i = 0;
	j = 0;
	start = 0;
	nbr_words = count_words(str);
	tab = malloc(sizeof(char *) * (nbr_words + 1));
	if (!tab)
		return (NULL);
	while (str[i])
	{
		if (!is_space(str[i]))
		{
			start = i;
			while (str[i] && !is_space(str[i]))
				i++;
			tab[j] = word_dup(str, start, i);
			j++;
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		char	**split;
		int		i;
		int		j;

		i = 0;
		split = ft_split(argv[1]);
		while (split[i])
		{
			j = 0;
			while (split[i][j])
			{
				write(1, &split[i][j], 1);
				j++;
			}
			write(1, " ", 1);
			i++;
		}
		write(1, "\n", 1);
	}
}