/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:00:12 by yfontene          #+#    #+#             */
/*   Updated: 2023/11/27 17:37:14 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_type(char fmt, va_list args)
{
	int	c;

	c = 0;
	if (fmt == '%')
		c += ft_putchar('%');
	else if (fmt == 'c')
		c += ft_putchar(va_arg(args, int));
	else if (fmt == 's')
		c += ft_putstr(va_arg(args, char *));
	else if (fmt == 'd' || fmt == 'i')
		c += ft_putnbr(va_arg(args, int));
	else if (fmt == 'u')
		c += ft_dec_base(va_arg(args, unsigned int));
	else if (fmt == 'x' || fmt == 'X')
		c += ft_hex_base(va_arg(args, unsigned int), fmt);
	else if (fmt == 'p')
		c += ft_put_p(va_arg(args, void *));
	return (c);
}
