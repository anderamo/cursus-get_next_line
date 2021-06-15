/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:12:33 by aamorin-          #+#    #+#             */
/*   Updated: 2021/06/15 19:24:13 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

int		get_next_line(int fd, char **line);
void	*ft_memcpy(void *destination, const void *source, size_t num);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(char *str);
char	*ft_strdup(const char *src);

#endif
