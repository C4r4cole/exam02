/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:31:13 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/17 17:33:23 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

int	ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

struct s_list	*create_node(char *whatever)
{
	struct s_list	*new_node;
	
	new_node = malloc(sizeof(struct s_list));
	if (!new_node)
		return (0);
	new_node->data = whatever;
	new_node->next = NULL;
	return (new_node);
}

void	push_front(struct s_list **head, char *whatever)
{
	struct s_list *new_node;
	
	new_node = create_node(whatever);
	new_node->next = *head;
	*head = new_node;
}

int	main(void)
{
	struct s_list	*my_list;
	
	my_list = NULL;
	push_front(&my_list, "coucou");
	push_front(&my_list, "ca");
	push_front(&my_list, "va");
	push_front(&my_list, "bien");
	printf("%d", ft_list_size(my_list));
	return (0);
}