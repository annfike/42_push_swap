/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <adelaloy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:16:50 by adelaloy          #+#    #+#             */
/*   Updated: 2023/12/26 12:16:51 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	size_scr;

	size_scr = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (size_scr);
}

static int	count_words(char const *s, char c)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			n += 1;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (n);
}

static char	**make_arr_words(char **dst, char const *s, int n, char c)
{
	int	i;
	int	j;
	int	word_len;

	i = 0;
	j = 0;
	word_len = 0;
	while (i < n)
	{
		if (s[j] && s[j] != c)
			word_len++;
		else if (s[j] == c || s[j] == '\0')
		{
			if (word_len > 0)
			{
				dst[i] = (char *)malloc(sizeof(char) * (word_len + 1));
				if (dst[i])
					ft_strlcpy(dst[i], (s + j - word_len), word_len + 1);
				i++;
				word_len = 0;
			}
		}
		j++;
	}
	return (dst);
}

char	**ft_split(char const *s, char c, t_data *data)
{
	int		n;
	char	**dst;

	n = count_words(s, c);
	data->size = n;
	dst = (char **)malloc(sizeof(char *) * (n + 1));
	if (!dst)
		return (NULL);
	dst = make_arr_words(dst, s, n, c);
	dst[n] = (void *)0;
	return (dst);
}
