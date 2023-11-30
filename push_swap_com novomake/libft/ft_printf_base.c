/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:41:46 by yfontene          #+#    #+#             */
/*   Updated: 2023/11/27 17:37:04 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(const char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (write(1, "0", 1));
	if (nb == -2147483648)
	{
		i += ft_putstr("-2147483648");
		return (i);
	}
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putchar((nb % 10) + 48);
	}
	else
	{
		i += ft_putchar(nb + 48);
	}
	return (i);
}

int	ft_dec_base(unsigned int nb)
{
	char	*base;
	int		c ;

	base = "0123456789";
	c = 0;
	if (nb >= 10)
		c += ft_dec_base(nb / 10);
	c += ft_putchar(base[nb % 10]);
	return (c);
}
