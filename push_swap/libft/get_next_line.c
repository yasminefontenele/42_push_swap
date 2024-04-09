/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 07:53:39 by yfontene          #+#    #+#             */
/*   Updated: 2023/06/06 07:53:39 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*reads data from a file descriptor (fd) and appends it to an string*/
char	*ft_read_file(int fd, char *read_line)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_srtsearch(read_line, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (read_line);
			free (buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		read_line = ft_strunite(read_line, buffer);
	}
	free (buffer);
	return (read_line);
}

/*returns a line read from a file descriptor (fd)*/
char	*ft_get_line(char *read_line)
{
	char	*line;
	int		i;

	i = 0;
	if (!read_line[i])
		return (NULL);
	while (read_line[i] && read_line[i] != '\n')
		i++;
	line = (char *) malloc (sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (read_line[i] && read_line[i] != '\n')
	{
		line[i] = read_line[i];
		i++;
	}
	if (read_line[i] == '\n')
	{
		line[i] = read_line[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

/*removes the first line from the read_line string and returns the
remaining text after a '\n'*/
char	*ft_get_rest(char *read_line)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	while (read_line[i] && read_line[i] != '\n')
		i++;
	if (!read_line[i])
	{
		free (read_line);
		return (NULL);
	}
	rest = (char *) malloc (sizeof(char) * (ft_width(read_line) - i + 1));
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (read_line[i])
		rest[j++] = read_line[i++];
	rest[j] = '\0';
	free (read_line);
	return (rest);
}

/*returns a line read from a file descriptor (fd)*/
char	*get_next_line(int fd)
{
	static char	*read_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_line = ft_read_file(fd, read_line);
	if (!read_line)
	{
		free (read_line);
		return (NULL);
	}
	line = ft_get_line(read_line);
	read_line = ft_get_rest(read_line);
	return (line);
}
