/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_old.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 10:39:40 by aamorin-          #+#    #+#             */
/*   Updated: 2021/06/10 10:39:47 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_chr(char *buffer, int c_position)
{
	return (buffer[c_position]);
}

static int	read_file_line(int fd, char *buf, char **line, int buf_size)
{
	static int		size;
	static int		c_position;
	static char		buffer[BUFFER_SIZE];
	int				chr;

	c_position = 0;
	size = read(fd, buffer, BUFFER_SIZE);
	while (1)
	{
		chr = get_chr(buffer, c_position);
		if (chr == 0 || chr == '\n')
		{
			buf[c_position] = '\0';
			*line = buf;
			return (1);
		}
		else
			buf[c_position] = chr;
		c_position++;
		if (c_position >= buf_size)
		{
			buf_size += BUFFER_SIZE;
			buf = my_realloc(buf, buf_size);
			if (!buf)
				return (-1);
		}
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char	*buf;
	int		buf_size;

	buf_size = BUFFER_SIZE;
	buf = malloc((buf_size) * sizeof(char));
	if (fd < 0 || !buf || line == NULL || buf_size < 0)
		return (-1);
	return (read_file_line(fd, buf, line, buf_size));
}
