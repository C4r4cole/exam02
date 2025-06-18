/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:04:11 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/18 14:48:03 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_length(int nbr)
{
	int count;
	long n;

	n = nbr;
	count = 0;
	if(n <= 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	char	*res;
	int		len;
	long	n;
	
	len = get_length(nbr);
	n = nbr;
	res = malloc(sizeof(char) * (len + 1));
	if(!res)
		return (NULL);
	res[len] = '\0';
	if (n == 0)
	{
		res[0] = '0';
		return (res);
	}
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		len--;
		res[len] = 48 + (n % 10);
		n = n / 10;
	}
	return (res);
}

#include <stdio.h>

int	main(void)
{
	char *res; 
	
	res = ft_itoa(-1234);
	printf("%s", res);
	return (0);
}