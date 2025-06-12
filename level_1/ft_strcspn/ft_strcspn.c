/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:20:08 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/12 12:05:54 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		printf("%zu", ft_strcspn(argv[1], argv[2]));
// 	}
// 	return (0);
// }