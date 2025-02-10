/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:56:53 by fpikkov           #+#    #+#             */
/*   Updated: 2024/05/22 23:10:12 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int nbr);
char	*ft_uitoa(unsigned int nbr);
int		ft_put_uint(unsigned int nbr);
int		ft_put_hex(unsigned int nbr, const char c);
int		ft_put_ptr(unsigned long ptr);
int		ft_printf(const char *format, ...);

#endif
