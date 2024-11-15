/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:17:01 by fpikkov           #+#    #+#             */
/*   Updated: 2024/09/16 16:06:09 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (*str >= '0' && *str <= '9' && (!(nbr > INT_MAX) || !(nbr < INT_MIN)))
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	nbr *= sign;
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	return ((int)nbr);
}
