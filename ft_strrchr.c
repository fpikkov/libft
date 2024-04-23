/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:06:36 by fpikkov           #+#    #+#             */
/*   Updated: 2024/04/18 16:14:34 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *) s;
	while (*ptr)
		ptr++;
	while (ptr >= s)
	{
		if (*ptr == c)
			return (ptr);
		ptr--;
	}
	return (0);
}
