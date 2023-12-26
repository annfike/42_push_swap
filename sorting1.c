/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <adelaloy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:20:01 by adelaloy          #+#    #+#             */
/*   Updated: 2023/12/26 13:05:05 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_min_moves(t_data *data, int moves)
{
	int	moves_min;

	moves_min = moves;
	data->ra = data->ra_tmp;
	data->rra = data->rra_tmp;
	data->rb = data->rb_tmp;
	data->rrb = data->rrb_tmp;
	return (moves_min);
}

void	set_data_for_new_loop(t_list **lst, t_data *data)
{
	data->min = ft_lst_min(*lst);
	data->max = ft_lst_max(*lst);
	data->rb_tmp = 0;
	data->rrb_tmp = 0;
	data->ra_tmp = 0;
	data->rra_tmp = 0;
}

static int	count_moves(t_list **b, t_data *data, int num, int i)
{
	int	moves;

	moves = find_place_in_b(num, *b, data);
	if (i < data->len / 2)
		data->ra_tmp = i;
	else
		data->rra_tmp = (data->len - i);
	if (data->len == 1)
		data->rra_tmp = 0;
	moves = data->ra_tmp + data->rra_tmp + data->rb_tmp + data->rrb_tmp + 1;
	return (moves);
}

void	sorting1(t_list **a, t_list **b, t_data *data)
{
	int		i;
	int		moves;
	int		moves_min;
	t_list	*tmp;

	moves_min = 1;
	tmp = *a;
	i = 0;
	data->len = ft_lstsize(*a);
	while (i < data->len)
	{
		set_data_for_new_loop(b, data);
		moves = count_moves(b, data, (*a)->num, i);
		if (i == 0)
			moves_min = set_min_moves(data, moves);
		if (moves < moves_min)
			moves_min = set_min_moves(data, moves);
		i++;
		*a = (*a)->next;
	}
	*a = tmp;
	rotate(a, b, data);
	push_to_b(a, b);
}
