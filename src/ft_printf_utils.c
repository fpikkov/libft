/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:57:59 by fpikkov           #+#    #+#             */
/*   Updated: 2024/05/22 20:58:22 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	size_t	len;

	if (!str)
		return (write(1, "(null)", 6));
	len = ft_strlen(str);
	return (write(1, str, len));
}

int	ft_putnbr(int nbr)
{
	int		len;
	char	*ptr;

	ptr = ft_itoa(nbr);
	if (ptr == NULL)
		return (-1);
	len = ft_putstr(ptr);
	free(ptr);
	return (len);
}
