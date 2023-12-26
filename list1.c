/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <adelaloy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:17:32 by adelaloy          #+#    #+#             */
/*   Updated: 2023/12/26 13:23:31 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_min(t_list *lst)
{
	int	min;

	min = lst->num;
	while (lst)
	{
		if (lst->num < min)
			min = lst->num;
		lst = lst->next;
	}
	return (min);
}

int	ft_lst_max(t_list *lst)
{
	int	max;

	max = lst->num;
	while (lst)
	{
		if (lst->num > max)
			max = lst->num;
		lst = lst->next;
	}
	return (max);
}

void	ft_lstdelone(t_list *lst)
{
	free(lst);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
