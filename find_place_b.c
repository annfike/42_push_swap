/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <adelaloy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:15:56 by adelaloy          #+#    #+#             */
/*   Updated: 2023/12/26 14:25:48 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_place_in_b_first_half(int a, t_list *b, t_data *data, int len)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = b;
	while (tmp->next != NULL && i < len / 2)
	{
		if ((a > data->max || a < data->min) && tmp->num == data->max)
		{
			data->rb_tmp = i;
			return (i);
		}
		if ((a > data->min && a < data->max) && (tmp->num > a
				&& tmp->next->num < a))
		{
			data->rb_tmp = i + 1;
			return (i + 1);
		}
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

static int	find_place_in_b_second_half(int a, t_list *b, t_data *data, int len)
{
	int		i;

	i = len / 2;
	while (b->next != NULL && i < len)
	{
		if ((a > data->max || a < data->min) && b->num == data->max)
		{
			data->rrb_tmp = (len - i);
			return (len - i);
		}
		if ((a > data->max || a < data->min) && b->next->num == data->max)
		{
			data->rrb_tmp = (len - i - 1);
			return (len - i - 1);
		}
		if ((a > data->min && a < data->max) && (b->num > a
				&& b->next->num < a))
		{
			data->rrb_tmp = (len - i + 1);
			return (len - i + 1);
		}
		b = b->next;
		i++;
	}
	return (0);
}

int	find_place_in_b(int a, t_list *b, t_data *data)
{
	int	result;
	int	len;

	len = ft_lstsize(b);
	result = find_place_in_b_first_half(a, b, data, len);
	if (result == -1)
		result = find_place_in_b_second_half(a, b, data, len);
	return (result);
}
