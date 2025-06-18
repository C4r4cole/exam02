/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:42:21 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/18 21:02:03 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*head;
	int		tmp;
	int		sorted;

	if(!lst)
		return (NULL);
	sorted = 0;
	head = lst;
	while (!sorted)
	{
		sorted = 1;
		while (lst->next)
		{
			if (cmp(lst->data, lst->next->data) == 0)
			{
				tmp = lst->data;
				lst->data = lst->next->data;
				lst->next->data = tmp;
				sorted = 0;
			}
			lst = lst->next;
		}
		lst = head;
	}
	return (head);
}