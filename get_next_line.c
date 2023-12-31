/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:14:33 by yususato          #+#    #+#             */
/*   Updated: 2023/06/08 15:10:59 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_next(char *buffer, char *line)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	tmp = (char *)ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!tmp)
	{
		free(buffer);
		return (line);
	}
	i++;
	while (buffer[i])
	tmp[j++] = buffer[i++];
	free(buffer);
	return (tmp);
}

char	*output(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] != '\0' && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*unit(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*read_file(int fd, char *buffer, int *flag)
{
	int		byte_size;
	char	*buf;

	byte_size = 1;
	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	while (byte_size > 0)
	{
		byte_size = read(fd, buf, BUFFER_SIZE);
		if (byte_size == -1)
		{
			flag = 0;
			free(buf);
			return (NULL);
		}
		buf[byte_size] = '\0';
		buffer = unit(buffer, buf);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buf);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			flag;

	flag = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer, &flag);
	if (flag == 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = output(buffer);
	buffer = line_next(buffer, line);
	return (line);
}
