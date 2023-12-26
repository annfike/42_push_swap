/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <adelaloy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:17:32 by adelaloy          #+#    #+#             */
/*   Updated: 2023/12/26 12:41:00 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_lstlast(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lst_issorted(t_list *lst)
{
	int		max;
	int		min;
	t_list	*i;
	int		j;
	int		a;

	i = ft_lstlast(lst);
	j = i->num;
	a = lst->num;
	max = ft_lst_max(lst);
	min = ft_lst_min(lst);
	while (lst->next != NULL)
	{
		if (lst->num == max && lst->next->num != min)
			return (0);
		if (lst->next->num < lst->num && lst->num != max)
			return (0);
		lst = lst->next;
	}
	if (a < j && a != min)
		return (0);
	return (1);
}

void	free_arr(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size)
	{
		free(data->arr[i]);
		i++;
	}
	free(data->arr);
}

void	free_lst(t_list **lst)
{
	t_list	*tmp;

	while (*lst != NULL)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}
