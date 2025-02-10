/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:54:58 by fpikkov           #+#    #+#             */
/*   Updated: 2024/05/22 23:09:56 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Conversion specifiers for ft_printf
static int	ft_formats(va_list ap, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (format == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (format == 'p')
		count += ft_put_ptr((unsigned long)va_arg(ap, void *));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (format == 'u')
		count += ft_put_uint(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		count += ft_put_hex(va_arg(ap, unsigned int), format);
	else if (format == '%')
		count += ft_putchar('%');
	return (count);
}

// Prints format string and any arguments after a specifier occurs
// Result checks for errors in write or malloc
// Specifiers: c, s, p, d/i, u, x/X
// @param *format string literal including format specifiers
int	ft_printf(const char *format, ...)
{
	int		num_chars;
	int		result;
	va_list	ap;

	result = 0;
	num_chars = 0;
	va_start(ap, format);
	while (*format && result != -1)
	{
		if (*format == '%')
			result = ft_formats(ap, *(++format));
		else
			result = ft_putchar(*format);
		num_chars += result;
		format++;
	}
	va_end(ap);
	if (result == -1)
		return (result);
	return (num_chars);
}
