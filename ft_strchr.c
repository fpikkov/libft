/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:35:04 by fpikkov           #+#    #+#             */
/*   Updated: 2024/04/29 14:15:47 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	ch;

	ch = (char) c;
	ptr = (char *) s;
	while (*ptr != ch && *ptr)
		ptr++;
	if (*ptr == ch)
		return (ptr);
	return (0);
}
