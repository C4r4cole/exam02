/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:30:15 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/10 10:46:11 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;
	
	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

// #include <stdio.h>
// 
// int	main(int argc, char **argv)
// {
// 	if (argc < 1)
// 		return (0);
// 	else
// 	{
// 		char *res;
// 		res = ft_strcpy(argv[1], argv[2]);
// 		printf("%s", res);
// 	}
// 	return (0);
// }