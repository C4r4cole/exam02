/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:48:41 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/17 16:29:13 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_digit_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 10);
	else
		return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	sign;
	int nb;
	int	digit;
	
	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '-')
		sign = sign * -1;
	while(str[i])
	{
		digit = get_digit_value(str[i]);
		if (digit != -1)
			nb = nb * str_base + digit;		
		i++;
	}
	return (nb * sign);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		printf("%d", ft_atoi_base(argv[1], atoi(argv[2])));
// 	}
// 	else
// 		return (0);
// }