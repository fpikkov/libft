/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:38:39 by fpikkov           #+#    #+#             */
/*   Updated: 2024/05/03 21:04:06 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Counts the total amount of splits required
static size_t	ft_total_splits(char const *s, char c)
{
	size_t	splits;
	int		word;

	splits = 0;
	word = 0;
	while (*s)
	{
		if (*s == c)
			word = 0;
		if (*s != c && word == 0)
		{
			word = 1;
			splits++;
		}
		s++;
	}
	return (splits);
}

// Frees the memory in case of allocation failure
static char	**ft_error(char **arr, size_t i)
{
	while (i)
		free(arr[--i]);
	free(arr);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	splits;
	size_t	index;

	index = 0;
	splits = ft_total_splits(s, c);
	ptr = (char **)malloc((splits + 1) * sizeof(char *));
	if (!ptr)
		return (ft_error(ptr, index));
	while (index < splits)
	{
		while (*s == c)
			s++;
		ptr[index] = ft_substr(s, 0, (ft_strchr(s, c) - s));
		if (!ptr[index])
			return (ft_error(ptr, index));
		while (*s != c && *s)
			s++;
		index++;
	}
	ptr[index] = 0;
	return (ptr);
}
