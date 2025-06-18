/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:56:54 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/18 19:43:02 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	is_space(char c)
{
	return (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32);
}

int	count_words(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (!is_space(str[i]))
		{
			if (str[i] && (i == 0 || is_space(str[i - 1])))
				count++;
		}
		i++;
	}
	return (count);
}

char	*ft_strdup(char *str, int start, int end)
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
		start ++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**tab;
	int		words;
	int		i;
	int		j;
	int		start;
	
	i = 0;
	j = 0;
	start = 0;
	words = count_words(str);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	while (str[i])
	{
		if (str[i] && (i == 0 || is_space(str[i - 1])))
		{
			start = i;
			while (str[i] && !is_space(str[i]))
				i++;
			tab[j] = ft_strdup(str, start, i);
			j++;
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		write(1, "\n", 1);
	else
	{
		char 	*str;
		char 	**splited_tab;
		int		i;
		int		j;
		
		str = argv[1];
		i = count_words(str) - 1;
		splited_tab = ft_split(str);
		while (i >= 0)
		{
			j = 0;
			while(splited_tab[i][j])
			{
				write(1, &splited_tab[i][j], 1);
				j++;
			}
			write(1, " ", 1);
			i--;
		}
		write(1, "\n", 1);
	}
	return (0);
}