/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:16:31 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/26 13:26:32 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*calloc1(size_t element_count, size_t element_size)
{
	char	*ptr;
	size_t	total_size;

	total_size = element_count * element_size;
	ptr = (void *)malloc(total_size);
	if (!ptr)
	{
		return (NULL);
	}
	ft_bzero1(ptr, total_size);
	return (ptr);
}

static char	*ft_read(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = calloc1((BUFFER_SIZE + 1), sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			free(left_str);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin1(left_str, buff);
		if (ft_strchr1(buff, '\n'))
			break ;
	}
	free(buff);
	buff = NULL;
	return (left_str);
}

static char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] != '\n' && buffer[i] == '\0')
	{
		line = calloc1(i + 1, sizeof(char));
	}
	else
		line = calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

static char	*ft_rest(char *save)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	s = (char *)calloc1(sizeof(char), (ft_strlen1(save) - i));
	if (!s)
	{
		free(s);
		return (NULL);
	}
	i++;
	c = 0;
	while (save[i])
		s[c++] = save[i++];
	s[c] = '\0';
	free(save);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*buf[1045];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf[fd] = ft_read(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	line = ft_line(buf[fd]);
	buf[fd] = ft_rest(buf[fd]);
	return (line);
}
