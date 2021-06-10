/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:07:53 by aamorin-          #+#    #+#             */
/*   Updated: 2021/06/10 12:50:56 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_file_line(char *buf, char **line)
{
	static int		c_position;

	c_position = 0;
	while (BUFFER_SIZE > c_position)
	{
		if (buf[c_position] == '\n')
		{
			buf[c_position] = '\0';
			*line = buf;
			printf("%s\n", *line);
			return (1);
		}
		c_position++;
	}
	buf[c_position] = '\0';
	*line = buf;
	printf("%s\n", *line);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char	*buf;
	int		buf_size;
	int		size;

	buf_size = BUFFER_SIZE;
	size = 1;
	buf = malloc((buf_size + 1) * sizeof(char));
	if (fd < 0 || line == NULL || buf_size <= 0 || !buf)
		return (-1);
	while (size != 0)
	{
		if ((size = read(fd, buf, buf_size)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[size] = '\0';
	}
	return (read_file_line(buf, line));
}
