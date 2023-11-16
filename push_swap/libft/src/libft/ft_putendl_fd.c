/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:47:09 by yfontene          #+#    #+#             */
/*   Updated: 2023/11/15 18:05:25 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Outputs the string ’s’ to the given file descriptor, followed by a newline.*/

#include "../../library/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
	}
}

/*int	main(void)
{
	char	s[] = "Yasmine";
	int		fd;
	fd = 1;
	ft_putendl_fd(s, fd);
	return (0);
}*/
