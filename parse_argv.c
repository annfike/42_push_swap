/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <adelaloy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:18:10 by adelaloy          #+#    #+#             */
/*   Updated: 2023/12/26 13:16:27 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}

static void	error(t_data *data)
{
	write(1, "Error\n", 6);
	free_arr(data);
	exit(1);
}

int	ft_atoi_check_isint(const char *str, t_data *data)
{
	int		i;
	int		minus;
	long	n;

	i = 0;
	minus = 1;
	n = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	if ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
		error(data);
	if ((n * minus) < -2147483648 || (n * minus) > 2147483647)
		error(data);
	return (n * minus);
}

void	data_argv(int argc, char **argv, t_data *data)
{
	int	i;

	i = 0;
	if (argc == 1)
		return ;
	if (argc == 2)
		data->arr = ft_split(argv[1], ' ', data);
	else
	{
		data->arr = (char **)malloc(sizeof(char *) * (argc - 1));
		while (i < (argc - 1))
		{
			data->arr[i] = (char *)malloc(sizeof(char)
					* (ft_strlen(argv[i + 1]) + 1));
			ft_strlcpy(data->arr[i], argv[i + 1], ft_strlen(argv[i + 1]) + 1);
			i++;
		}
		data->size = i;
	}
	i = data->size - 1;
}

void	check_argv(t_data *data)
{
	int	i;
	int	j;
	int	num;
	int	num1;

	i = 0;
	j = 0;
	num = 0;
	num1 = 0;
	while (i < data->size)
	{
		j = i + 1;
		while (j < data->size)
		{
			num = ft_atoi_check_isint(data->arr[i], data);
			num1 = ft_atoi_check_isint(data->arr[j], data);
			if (num == num1)
				error(data);
			j++;
		}
		i++;
	}
}
