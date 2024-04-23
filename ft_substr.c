/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:08:49 by fpikkov           #+#    #+#             */
/*   Updated: 2024/04/22 11:20:30 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)malloc(len * sizeof(char));
	if (!ptr)
		return (0);
	i = 0;
	while (len)
	{
		ptr[i] = s[start + i];
		i++;
		len--;
	}
	return (ptr);
}
