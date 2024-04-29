/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:58:26 by fpikkov           #+#    #+#             */
/*   Updated: 2024/04/25 17:52:08 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*source;

	ptr = (unsigned char *) dst;
	source = (unsigned char *) src;
	if (!dst && !src)
		return (dst);
	while (n--)
	{
		*ptr++ = *source++;
	}
	return (dst);
}
