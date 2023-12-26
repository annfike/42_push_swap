/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <adelaloy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:19:48 by adelaloy          #+#    #+#             */
/*   Updated: 2023/12/26 12:19:49 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = (*a)->next;
	ft_lstadd_front(b, ft_lstnew((*a)->num));
	ft_lstdelone(*a);
	*a = tmp;
	write(1, "pb\n", 3);
}

void	push_to_a(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = (*b)->next;
	ft_lstadd_front(a, ft_lstnew((*b)->num));
	ft_lstdelone(*b);
	*b = tmp;
	write(1, "pa\n", 3);
}

void	swap(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	tmp2 = *lst;
	tmp = tmp->next;
	tmp2->next = tmp->next;
	tmp->next = tmp2;
	*lst = tmp;
	write(1, "sa\n", 3);
}
