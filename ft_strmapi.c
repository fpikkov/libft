/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:30:33 by fpikkov           #+#    #+#             */
/*   Updated: 2024/04/24 12:46:36 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*ptr;

	if (!(ptr = (char *)malloc(ft_strlen(s) * sizeof(char))))
		return (0);
	index = 0;
	while (ptr[index] != '\0')
	{
		ptr[index] = (*f)(index, s[index]);
		index++;
	}
	return (ptr);
}
