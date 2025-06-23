/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_test2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:52:12 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/19 11:30:31 by fmoulin          ###   ########.fr       */
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

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] && !is_space(str[i]) && (i == 0 || is_space(str[i - 1])))
			count++;
		i++;
	}
	return (count);
}

char	*ft_strdup(char *str, int start, int end)
{
	char	*word;
	int		len;
	int		i;

	len = end - start + 1;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return(NULL);
	i = 0;
	while(start < end)
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
	int		words;
	int		i;
	int		j;
	int		start;

	words = count_words(str);
	tab = malloc((sizeof(char *) * (words + 1)));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] && !is_space(str[i]) && (i == 0 || is_space(str[i - 1])))
		{
			start = i;
			while (str[i] && !is_space(str[i]))
				i++;
			tab[j] = ft_strdup(str, start, i);
			j++;
		}
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
		int		i;
		int		j;
		char	**split;

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
			write(1, "*", 1);
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}