/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:07:38 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/11 16:26:56 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;
	int	res;

	i = 0;
	while (i < n)
	{
		res = s1[i] - s2[i];
		i++;
	}
	return (res);
}

int	do_op(int nbr1, char *op, int nbr2)
{
	long	result;

	result = 0;
	if (ft_strncmp(op, "+", 1) == 0)
		result = (long)nbr1 + (long)nbr2;
	else if (ft_strncmp(op, "-", 1) == 0)
		result = (long)nbr1 - (long)nbr2;
	else if (ft_strncmp(op, "*", 1) == 0)
		result = (long)nbr1 * (long)nbr2;
	else if (ft_strncmp(op, "/", 1) == 0)
		result = (long)nbr1 / (long)nbr2;
	else if (ft_strncmp(op, "%", 1) == 0)
		result = (long)nbr1 % (long)nbr2;
	return (result);
}

int	main(int argc, char **argv)
{
	int	result;
	
	if (argc != 4)
		write(1, "\n", 1);
	else
	{
		result = do_op(atoi(argv[1]), argv[2], atoi(argv[3]));
		printf("%d", result);
	}
	return (0);
}