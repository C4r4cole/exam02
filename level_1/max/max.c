/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:59:40 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/13 12:15:25 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int *tab, unsigned int len)
{
	unsigned int	i;
	unsigned int	tmp;

	i = 0;
	if (!tab)
		return (0);
	while (i < len)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
		}
		i++;
	}
	return (tab[len]);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	tab[9] = {12, 28, 1, 79, 48, 2263, 24, 256, 6};
// 	int	len;

// 	len = 9;
// 	printf("%d", max(tab, len));	
// 	return (0);
// }
