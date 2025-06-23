/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 08:25:51 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/23 08:53:39 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	len;
	int	*tab;
	int	i;
	
	if (start >= end)
		len = (start - end) + 1;
	else
		len = (end - start) + 1;
	tab = malloc(sizeof(int) * len);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < len)
	{
		tab[i] = end;
		if (end > start)
			end--;
		else
			end++;
		i++;
	}
	return (tab);
}

#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 3)
		write(1, "\n", 1);
	else
	{
		int	start;
		int	end;
		int	i;
		int	*tab;
		int	len;

		start = atoi(argv[1]);
		end = atoi(argv[2]);
		i = 0;
		if (start >= end)
			len = (start - end) + 1;
		else
			len = (end - start) + 1;
		tab = ft_rrange(start, end);
		while (i < len)
		{
			printf("%d, ", tab[i]);
			i++;
		}
		printf("\n");
	}
}