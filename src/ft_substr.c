/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:08:49 by fpikkov           #+#    #+#             */
/*   Updated: 2024/05/03 20:40:16 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 0 < 0 evaluates to False which handles the edge case
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	lenstr;

	lenstr = ft_strlen(s);
	if ((size_t)start >= lenstr)
		len = 0;
	else if (len > lenstr || (size_t)start + len > lenstr)
		len = lenstr - start;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (0);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[(size_t)start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
