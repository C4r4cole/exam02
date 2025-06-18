/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:08:02 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/18 17:53:25 by fmoulin          ###   ########.fr       */
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
		if(!is_space(str[i]))
		{
			if (i == 0 || is_space(str[i - 1]))
				count++;
		}
		i++;
	}
	return (count);
}

char	*word_dup(char *str, int start, int end)
{
	int	i;
	char *dup;

	i = 0;
	dup = malloc (sizeof(char) * (end - start + 1));
	if (!dup)
		return (NULL);
	while (start < end)
	{
		dup[i] = str[start];
		i++;
		start++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char *str)
{
	char	**tab;
	int		words;
	int		i;
	int		j;
	int		start;

	i = 0;
	words = count_words(str);
	tab = malloc(sizeof(char *) * (words + 1));
	if(!tab)
		return(NULL);
	while (str[i])
	{
		if (!is_space(str[i]))
		{
			start = i;
			while(str[i] && !is_space(str[i]))
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