/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:35:09 by fpikkov           #+#    #+#             */
/*   Updated: 2024/04/24 11:27:24 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_char_counter(int nbr)
{
	size_t	len;

	len = 1;
	if (nbr < 0)
		len++;
	while ((nbr / 10) != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*arg;
	size_t	count;
	int		sign;

	sign = 1;
	count = ft_char_counter(n);
	arg = (char *)malloc(count * sizeof(char));
	if (!arg)
		return (0);
	arg[count] = '\0';
	if (n < 0)
	{
		sign *= -1;
		n *= sign;
	}
	while (count--)
	{
		arg[count] = (n % 10 + '0');
		n = n / 10;
	}
	if (sign < 0)
		arg[++count] = '-';
	return (arg);
}
