/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 01:19:55 by ivan              #+#    #+#             */
/*   Updated: 2024/03/21 20:09:21 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*joinfreefile(char *buffer, char *buff)
{
	char	*buff_t;

	buff_t = ft_strjoin(buffer, buff);
	free(buffer);
	return (buff_t);
}

char	*read_file(int fd, char *file)
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
		file = joinfreefile(file, buff);
		if (ft_strchr(file, '\n'))
			break ;
	}
	free(buff);
	return (file);
}
char	*get_next_line(int fd)
{
	char	*file;

	file = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd,0 , 0) < 0)
		return (NULL);
	file = read_file(fd, file);
	if (!file)
		return (NULL);
	return (file);
}

int     main(int argc, char *argv[])
{
        char    *line;
        int             file;

        if (argc != 2)
                return (1);
        file = open(argv[1], O_RDONLY);
        line = get_next_line(file);
        printf("%s", line);
        line = get_next_line(file);
        printf("%s", line);
        line = get_next_line(file);
        printf("%s", line);
}
