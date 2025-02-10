/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:59:09 by fpikkov           #+#    #+#             */
/*   Updated: 2024/05/22 22:22:15 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Finds the size to be mallocated
static int	ft_uint_counter(unsigned int nbr)
{
	int	len;

	len = 1;
	while ((nbr / 10) != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

// Convert unsigned integer to argument
char	*ft_uitoa(unsigned int nbr)
{
	char	*arg;
	int		len;

	len = ft_uint_counter(nbr);
	arg = (char *)malloc((len + 1) * sizeof(char));
	if (!arg)
		return (0);
	arg[len] = '\0';
	while (len--)
	{
		arg[len] = (nbr % 10 + '0');
		nbr = nbr / 10;
	}
	return (arg);
}

// Prints the unsigned integer
int	ft_put_uint(unsigned int nbr)
{
	int		len;
	char	*ptr;

	ptr = ft_uitoa(nbr);
	if (ptr == NULL)
		return (-1);
	len = ft_putstr(ptr);
	free(ptr);
	return (len);
}
