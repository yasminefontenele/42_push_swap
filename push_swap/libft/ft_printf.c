/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 07:54:34 by yfontene          #+#    #+#             */
/*   Updated: 2023/05/11 07:54:34 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Your function has to handle the following conversions: cspdiuxX%
** c: char  s: string  p: void pointer  d, i: integer (decimal base)
** u: unsigned integer (decimal base)  x, X: unsigned integer (hexadecimal base)
** %: percent sign literal */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start (args, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			count += ft_printf_type(fmt[i], args);
		}
		else
		{
			ft_putchar(fmt[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

/*int	main(void)
{
	int	*ptr;

	ft_printf("%c\n", 'a');
	ft_printf("%s\n", "Hello World!");
	ft_printf("%p\n", &ptr);
	ft_printf("%d\n", -42);
	ft_printf("%i\n", 42);
	ft_printf("%u\n", 42);
	ft_printf("%x\n", 0x0);
	ft_printf("%X\n", 0x2FFE);
	ft_printf("%%\n");
	return (0);
}*/
