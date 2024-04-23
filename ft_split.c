/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:38:39 by fpikkov           #+#    #+#             */
/*   Updated: 2024/04/23 18:10:57 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Splits should start at one to properlly mallocate the array
static size_t	ft_split_amount(char const *s, char c)
{
	size_t	splits;

	splits = 1;
	while (*s++)
		if (*s == c)
			splits++;
	return (splits);
}

static size_t	ft_find_end(char const *s, char c, size_t start)
{
	size_t	end;

	end = start;
	while (s[end] != c && s[end] != '\0')
		end++;
	return (end);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	splits;
	size_t	start;
	size_t	index;
	size_t	end;

	splits = ft_split_amount(s, c);
	ptr = (char **)malloc((splits + 1) * sizeof(char *));
	if (!ptr)
		return (0);
	start = 0;
	index = 0;
	while (index < splits)
	{
		end = ft_find_end(s, c, start);
		ptr[index] = (char *)malloc((end - start + 1) * sizeof(char));
		ft_strlcpy(ptr[index], &s[start], (end - start + 1));
		index++;
		start = ++end;
	}
	ptr[index] = NULL;
	return (ptr);
}
