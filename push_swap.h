/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <adelaloy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:15:33 by adelaloy          #+#    #+#             */
/*   Updated: 2023/12/26 13:11:15 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_list
{
	int				num;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	char	**arr;
	int		size;
	int		max;
	int		min;
	int		rb_tmp;
	int		rrb_tmp;
	int		ra_tmp;
	int		rra_tmp;
	int		rb;
	int		rrb;
	int		ra;
	int		rra;
	int		len;
}	t_data;

/*main.c*/
void	sort2(t_list **a);
void	sort3(t_list **a);
void	sort4(t_list **a, t_list **b, t_data *data);
void	sort5_and_more(t_list **a, t_list **b, t_data *data);

/*parse_argv.c*/
void	*ft_memset(void *s, int c, size_t n);
void	data_argv(int argc, char **argv, t_data *data);
int		ft_atoi_check_isint(const char *str, t_data *data);
void	check_argv(t_data *data);

/*ft_split.c*/
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**ft_split(char const *s, char c, t_data *data);

/*list.c*/
void	ft_create_stack(t_list **list, t_data *data);
t_list	*ft_lstnew(int num);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);

/*list1.c*/
int		ft_lst_min(t_list *lst);
int		ft_lst_max(t_list *lst);
void	ft_lstdelone(t_list *lst);
int		ft_lstsize(t_list *lst);

/*list2.c*/
int		ft_lst_issorted(t_list *lst);
void	free_arr(t_data *data);
void	free_lst(t_list **lst);

/*rotate.c*/
void	rotate_ra_rb(t_list **lst, char c);
void	rotate_rra_rrb(t_list **a, char c);
void	rotate(t_list **a, t_list **b, t_data *data);

/*push_swap.c*/
void	push_to_b(t_list **a, t_list **b);
void	push_to_a(t_list **a, t_list **b);
void	swap(t_list **lst);

/*find_place_b.c*/
int		find_place_in_b(int a, t_list *b, t_data *data);

/*sorting1.c*/
int		set_min_moves(t_data *data, int moves);
void	set_data_for_new_loop(t_list **lst, t_data *data);
void	sorting1(t_list **a, t_list **b, t_data *data);

/*find_place_a.c*/
void	find_place_in_a(int a, t_list *b, t_data *data);

/*sorting2.c*/
void	sorting2(t_list **a, t_list **b, t_data *data);
void	check_for_final_rotate_a(t_list **a, t_data *data);

#endif