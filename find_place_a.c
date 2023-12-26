/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <adelaloy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:15:49 by adelaloy          #+#    #+#             */
/*   Updated: 2023/12/26 15:24:29 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	count_ra(int b, t_list *a, t_data *data, int i)
{
	if ((b > data->max || b < data->min) && a->num == data->min)
		data->ra_tmp = i;
	else if ((b > data->min && b < data->max) && (a->num < b
			&& a->next->num > b))
		data->ra_tmp = i + 1;
}

void	find_place_in_a(int b, t_list *a, t_data *data)
{
	int		i;
	int		len;

	i = 0;
	len = ft_lstsize(a);
	while (a->next != NULL)
	{
		if (i < len / 2)
		{
			count_ra(b, a, data, i);
		}
		else
		{
			if ((b > data->max || b < data->min) && a->next->num == data->min)
				data->rra_tmp = (len - i - 1);
			else if ((b > data->max || b < data->min) && a->num == data->min)
				data->rra_tmp = (len - i);
			else if ((b > data->min && b < data->max) && (a->num < b
					&& a->next->num > b))
				data->rra_tmp = (len - i - 1);
		}
		a = a->next;
		i++;
	}
}
