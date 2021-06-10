/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:00:05 by aamorin-          #+#    #+#             */
/*   Updated: 2021/06/10 10:54:25 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	size_t				i;
	unsigned char		*dest;
	unsigned char		*src;

	if (destination == NULL && source == NULL)
		return (NULL);
	i = 0;
	src = (unsigned char *) source;
	dest = (unsigned char *) destination;
	while (num > i)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *src)
{
	size_t	size;
	char	*dst;

	size = ft_strlen((char *)src) + 1;
	dst = malloc(size);
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, src, size);
	return (dst);
}
