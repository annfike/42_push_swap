/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <adelaloy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:19:55 by adelaloy          #+#    #+#             */
/*   Updated: 2023/12/26 12:19:56 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ra_rb(t_list **lst, char c)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	tmp2 = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tmp2;
	*lst = tmp2->next;
	tmp2->next = NULL;
	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
}

void	rotate_rra_rrb(t_list **lst, char c)
{
	t_list	*tmp;
	t_list	*begin;
	int		i;

	tmp = *lst;
	begin = *lst;
	i = ft_lstsize(*lst);
	while (i > 2)
	{
		tmp = tmp->next;
		i--;
	}
	*lst = tmp->next;
	(*lst)->next = begin;
	tmp->next = NULL;
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
}

static void	rotate_rr(t_list **a, t_list **b, t_data *data)
{
	rotate_ra_rb(a, 'r');
	rotate_ra_rb(b, 'r');
	data->ra--;
	data->rb--;
	write(1, "rr\n", 3);
}

static void	rotate_rrr(t_list **a, t_list **b, t_data *data)
{
	rotate_rra_rrb(a, 'r');
	rotate_rra_rrb(b, 'r');
	data->rra--;
	data->rrb--;
	write(1, "rrr\n", 4);
}

void	rotate(t_list **a, t_list **b, t_data *data)
{
	while (data->ra > 0 && data->rb > 0)
		rotate_rr(a, b, data);
	while (data->rra > 0 && data->rrb > 0)
		rotate_rrr(a, b, data);
	while (data->ra > 0)
	{
		rotate_ra_rb(a, 'a');
		data->ra--;
	}
	while (data->rb > 0)
	{
		rotate_ra_rb(b, 'b');
		data->rb--;
	}
	while (data->rra > 0)
	{
		rotate_rra_rrb(a, 'a');
		data->rra--;
	}
	while (data->rrb > 0)
	{
		rotate_rra_rrb(b, 'b');
		data->rrb--;
	}
}
