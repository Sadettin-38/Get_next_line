/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfidan <sfidan@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:45:59 by sfidan            #+#    #+#             */
/*   Updated: 2022/08/30 13:46:01 by sfidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_crop_next(char *buf, char *loc)
{
	int		i;
	char	*res;

	if (!*loc)
	{
		free(buf);
		return (0);
	}
	res = ft_calloc((ft_strlen(loc)), sizeof(char));
	i = 0;
	while (*loc++)
		res[i++] = *loc;
	free(buf);
	return (res);
}

char	*ft_crop_line(char *buf, size_t i)
{
	char	*line;

	if (!*buf)
		return (0);
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] && buf[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *res)
{
	char	*buf;
	char	*temp;
	int		b;

	if (!res)
		res = ft_calloc(1, 1);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	b = 1;
	while (b > 0 && !ft_char_loc(buf, '\n', 1))
	{
		b = read(fd, buf, BUFFER_SIZE);
		if (b == -1)
		{
			free(buf);
			return (0);
		}
		buf[b] = 0;
		temp = ft_strjoin(res, buf);
		free(res);
		res = temp;
	}
	free(buf);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	buf = read_file(fd, buf);
	if (!buf)
		return (0);
	line = ft_crop_line(buf, ft_char_loc(buf, '\n', 0));
	buf = ft_crop_next(buf, buf + ft_char_loc(buf, '\n', 0));
	return (line);
}
