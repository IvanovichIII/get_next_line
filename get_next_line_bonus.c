/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:16:18 by igomez-s          #+#    #+#             */
/*   Updated: 2024/03/31 18:25:26 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*ft_joinfreefile(char *buffer, char *buff)
{
	char	*buff_t;

	buff_t = ft_strjoin(buffer, buff);
	free(buffer);
	return (buff_t);
}

char	*ft_nextline(char *buff)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	line = ft_calloc(ft_strlen(buff) - i + 1, sizeof(char));
	j = 0;
	i++;
	while (buff[i])
		line[j++] = buff[i++];
	free(buff);
	return (line);
}

char	*ft_line(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] && buff[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_read_file(int fd, char *file)
{
	char	*buff;
	int		byte;

	if (!file)
		file = ft_calloc(1, 1);
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte = 1;
	while (byte > 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buff);
			free(file);
			return (NULL);
		}
		buff[byte] = 0;
		file = ft_joinfreefile(file, buff);
		if (ft_strchr(file, '\n'))
			break ;
	}
	free(buff);
	return (file);
}

char	*get_next_line(int fd)
{
	static char	*file[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file[fd] = ft_read_file(fd, file[fd]);
	if (!file[fd])
		return (NULL);
	line = ft_line(file[fd]);
	file[fd] = ft_nextline(file[fd]);
	return (line);
}
