/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 07:13:22 by yfontene          #+#    #+#             */
/*   Updated: 2023/05/11 07:13:22 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(const char c);
int	ft_putstr(const char *str);
int	ft_putnbr(int nb);
int	ft_dec_base(unsigned int nb);
int	ft_hex_base(unsigned long nb, int fmt);
int	ft_put_p(void *ptr);
int	ft_printf_type(char fmt, va_list args);
int	ft_printf(const char *fmt, ...);

#endif
