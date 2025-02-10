/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:02:01 by fpikkov           #+#    #+#             */
/*   Updated: 2024/05/25 17:53:33 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex(unsigned int nbr, const char c)
{
	static char	*hex;
	int			count;

	count = 0;
	if (c == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (nbr >= 16)
		count = ft_put_hex((nbr / 16), c);
	if (count == -1)
		return (-1);
	if (ft_putchar(hex[nbr % 16]) == -1)
		return (-1);
	return (count + 1);
}

static int	ft_put_address(unsigned long nbr)
{
	static char	*hex;
	int			count;

	hex = "0123456789abcdef";
	count = 0;
	if (nbr >= 16)
		count = ft_put_address((nbr / 16));
	if (count == -1)
		return (-1);
	if (ft_putchar(hex[nbr % 16]) == -1)
		return (-1);
	return (count + 1);
}

int	ft_put_ptr(unsigned long ptr)
{
	int		len;

	if (write(1, "0x", 2) == -1)
		return (-1);
	len = ft_put_address(ptr);
	if (len == -1)
		return (len);
	return (len += 2);
}
