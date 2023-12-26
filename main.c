/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <adelaloy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:15:01 by adelaloy          #+#    #+#             */
/*   Updated: 2023/12/26 13:22:38 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_list **a)
{
	t_list	*tmp;
	int		a1;
	int		a2;

	tmp = *a;
	a1 = tmp->num;
	a2 = tmp->next->num;
	if (a1 > a2)
	{
		swap(&tmp);
	}
	*a = tmp;
}

void	sort3(t_list **a)
{
	t_list	*tmp;
	int		min;
	int		max;

	tmp = *a;
	min = ft_lst_min(tmp);
	max = ft_lst_max(tmp);
	if (tmp->num == min && tmp->next->num == max)
	{
		swap(&tmp);
		rotate_ra_rb(&tmp, 'a');
	}
	if (tmp->next->num == min && tmp->next->next->num == max)
		swap(&tmp);
	if (tmp->next->num == min && tmp->num == max)
		rotate_ra_rb(&tmp, 'a');
	if (tmp->next->next->num == min && tmp->next->num == max)
		rotate_rra_rrb(&tmp, 'a');
	if (tmp->next->next->num == min && tmp->num == max)
	{
		rotate_ra_rb(&tmp, 'a');
		swap(&tmp);
	}
	*a = tmp;
}

void	sort4(t_list **a, t_list **b, t_data *data)
{
	if ((*a)->num != ft_lst_min(*a))
	{
		check_for_final_rotate_a(a, data);
		rotate(a, b, data);
	}
	if (ft_lst_issorted(*a) == 0)
	{
		push_to_b(a, b);
		sort3(a);
		push_to_a(a, b);
	}
}

void	sort5_and_more(t_list **a, t_list **b, t_data *data)
{
	if (ft_lst_issorted(*a) == 0)
	{
		push_to_b(a, b);
		push_to_b(a, b);
		while (ft_lstsize(*a) > 3 && ft_lst_issorted(*a) == 0)
			sorting1(a, b, data);
		sort3(a);
		while (ft_lstsize(*b) > 0)
			sorting2(a, b, data);
	}
	if ((*a)->num != ft_lst_min(*a))
	{
		check_for_final_rotate_a(a, data);
		rotate(a, b, data);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	ft_memset(&data, 0, sizeof(t_data));
	data_argv(argc, argv, &data);
	check_argv(&data);
	ft_create_stack(&a, &data);
	if (ft_lstsize(a) == 2)
		sort2(&a);
	else if (ft_lstsize(a) == 3)
		sort3(&a);
	else if (ft_lstsize(a) == 4)
		sort4(&a, &b, &data);
	else if (ft_lstsize(a) > 4)
		sort5_and_more(&a, &b, &data);
	free_arr(&data);
	free_lst(&a);
	return (0);
}
