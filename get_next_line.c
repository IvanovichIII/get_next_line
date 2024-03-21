/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 01:19:55 by ivan              #+#    #+#             */
/*   Updated: 2024/03/21 21:10:49 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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

	if (!*buff)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	line[i] = '\n';
	return (line);
}

char	*ft_read_file(int fd, char *file)
{
	char	*buff;
	int		byte;

	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!file)
		file = ft_calloc(1, 1);
	byte = 1;
	while (byte > 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[BUFFER_SIZE - 1] = 0;
		file = ft_joinfreefile(file, buff);
		if (ft_strchr(file, '\n'))
			break ;
	}
	free(buff);
	return (file);
}

char	*get_next_line(int fd)
{
	static char	*file;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	file = ft_read_file(fd, file);
	if (!file)
		return (NULL);
	line = ft_line(file);
	file = ft_nextline(file);
	return (line);
}
/*
int	main(int argc, char *argv[])
{
	char	*line;
	int		file;

	if (argc != 2)
		return (1);
	file = open(argv[1], O_RDONLY);
	line = get_next_line(file);
	printf("%s", line);
	line = get_next_line(file);
	printf("%s", line);
	line = get_next_line(file);
	printf("%s", line);
	line = get_next_line(file);
	printf("%s", line);
}
*/
