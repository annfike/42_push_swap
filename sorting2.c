/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <adelaloy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:20:09 by adelaloy          #+#    #+#             */
/*   Updated: 2023/12/26 13:01:12 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_moves(t_list **a, t_data *data, int num, int i)
{
	int	moves;

	find_place_in_a(num, *a, data);
	if (i <= data->len / 2)
		data->rb_tmp = i;
	else
		data->rrb_tmp = (data->len - i);
	moves = data->ra_tmp + data->rra_tmp + data->rb_tmp + data->rrb_tmp + 1;
	return (moves);
}

void	sorting2(t_list **a, t_list **b, t_data *data)
{
	int		i;
	int		moves;
	int		moves_min;
	t_list	*tmp;

	tmp = *b;
	data->len = ft_lstsize(*b);
	i = 0;
	moves_min = 1;
	while (i < data->len)
	{
		set_data_for_new_loop(a, data);
		moves = count_moves(a, data, (*b)->num, i);
		if (i == 0)
			moves_min = set_min_moves(data, moves);
		if (moves < moves_min)
			moves_min = set_min_moves(data, moves);
		i++;
		*b = (*b)->next;
	}
	*b = tmp;
	rotate(a, b, data);
	push_to_a(a, b);
}

static int	count_moves_final(int num, t_data *data, int i, int len)
{
	data->ra = 0;
	data->rra = 0;
	if (i < len / 2)
	{
		if (num == data->min)
		{
			data->ra = i;
			return (1);
		}
	}
	else
	{
		if (num == data->min)
		{
			data->rra = (len - i);
			return (1);
		}
	}
	return (0);
}

void	check_for_final_rotate_a(t_list **a, t_data *data)
{
	int		i;
	t_list	*tmp;
	int		len;

	i = 0;
	tmp = *a;
	len = ft_lstsize(*a);
	data->min = ft_lst_min(*a);
	while (tmp)
	{
		if (count_moves_final(tmp->num, data, i, len) == 1)
			return ;
		tmp = tmp->next;
		i++;
	}
	*a = tmp;
}
