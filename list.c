/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <adelaloy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:17:25 by adelaloy          #+#    #+#             */
/*   Updated: 2023/12/26 13:23:50 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_node_to_stack(t_list **list, char *argv, t_data *data)
{
	t_list	*new;
	int		num;

	num = ft_atoi_check_isint(argv, data);
	new = ft_lstnew(num);
	ft_lstadd_front(list, new);
}

void	ft_create_stack(t_list **list, t_data *data)
{
	int	i;

	i = data->size;
	while (i > 0)
	{
		add_node_to_stack(list, data->arr[i - 1], data);
		i--;
	}
}

t_list	*ft_lstnew(int num)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (tmp == 0)
		return (0);
	tmp->next = NULL;
	tmp->num = num;
	return (tmp);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!(*lst))
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	if (!(*lst))
		*lst = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
