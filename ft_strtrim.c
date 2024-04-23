/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:11:37 by fpikkov           #+#    #+#             */
/*   Updated: 2024/04/22 17:42:25 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_starttrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
	return (i);
}

static size_t	ft_endtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	match;

	i = 0;
	while (s1[i] != '\0')
		i++;
	i--;
	match = 0;
	j = 0;
	while (set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			j = 0;
			match++;
			i--;
		}
		else
			j++;
	}
	return (match);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	start;
	size_t	end;
	size_t	len;

	len = ft_strlen(s1);
	start = ft_starttrim(s1, set);
	end = ft_endtrim(s1, set);
	ptr = ft_substr(s1, start, (len - start - end));
	if (!ptr)
		return (0);
	return (ptr);
}
