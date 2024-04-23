/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:45:10 by fpikkov           #+#    #+#             */
/*   Updated: 2024/04/19 19:17:35 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dupe;
	size_t	len;

	len = ft_strlen(s1) + 1;
	dupe = (char *)ft_calloc(len, sizeof(char));
	if (!dupe)
		return (0);
	ft_strlcpy(dupe, s1, len);
	return (dupe);
}
