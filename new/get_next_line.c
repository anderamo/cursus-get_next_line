/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:49:29 by aamorin-          #+#    #+#             */
/*   Updated: 2021/06/15 19:15:31 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_save(char *save)
{
	int		i;
	int		j;
	char	*str2;

	if (!save)
		return (0);
	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	str2 = malloc((i + 1) * ((ft_strlen(save) - i) + 1));
	if (!str2)
		return (0);
	i++;
	while (save[i])
		str2[j++] = save[i++];
	str2[j] = '\0';
	free(save);
	return (str2);
}

int	has_return(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*read_file_line(char *str)
{
	int		c_position;
	char	*str2;

	if (!str)
		return (0);
	c_position = 0;
	while (str[c_position] && str[c_position] != '\n')
		c_position++;
	str2 = malloc((c_position + 1) * sizeof(char));
	if (!str2)
		return (0);
	c_position = 0;
	while (str[c_position] && str[c_position] != '\n')
	{
		str2[c_position] = str[c_position];
		c_position++;
	}
	str2[c_position] = '\0';
	return (str2);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	int			size;
	static char	*text;

	size = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !buf)
		return (-1);
	while (has_return(text) == 0 && size != 0)
	{
		if ((size = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[size] = '\0';
		text = ft_strjoin(text, buf);
	}
	free(buf);
	*line = read_file_line(text);
	text = get_save(text);
	if (size == 0)
		return (0);
	return (1);
}
