/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:34:57 by yfontene          #+#    #+#             */
/*   Updated: 2023/11/30 17:56:43 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_base(unsigned long nb, int fmt)
{
	int		c;
	char	*base;

	c = 0;
	if (nb == 0)
		return (write(1, "0", 1));
	if (fmt == 'x')
		base = "0123456789abcdef";
	if (fmt == 'X')
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		c += ft_hex_base(nb / 16, fmt);
		c += ft_hex_base(nb % 16, fmt);
	}
	else
		c += ft_putchar(base[nb]);
	return (c);
}

int	ft_put_p(void *ptr)
{
	int	adress;

	adress = 0;
	if (!ptr)
	{
		adress += write(1, "(nil)", 5);
		return (adress);
	}
	adress += write(1, "0x", 2) + ft_hex_base((unsigned long)ptr, 'x');
	return (adress);
}
