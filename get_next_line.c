/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 01:19:55 by ivan              #+#    #+#             */
/*   Updated: 2024/03/18 03:51:48 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	print_line(char *ptr)
{
	while (*ptr && *ptr != '\n')
		write(1, ptr++, 1);
}

int	ft_str_line_len(const char *ptr, size_t buff_size)
{
	int	i;

	i = 0;
	while (*ptr && *ptr != '\n' && buff_size > 0)
	{
		ptr++;
		i++;
		buff_size--;
	}
	if (*ptr || *ptr == '\n')
		return (i + 1);
	return (-1);
}

void	*ft_realloc(int fd, size_t buff_size)
{
	char	*ptr;
	int		len;
	int		read_byt;

	ptr = malloc(buff_size * sizeof(char));
	if (!ptr)
		return (NULL);
	read_byt = read(fd, ptr, buff_size);
	if (read_byt < 0)
		return (NULL);
	len = ft_str_line_len(ptr, buff_size);
	if (len == -1)
	{
		free (ptr);
		return (NULL);
	}
	return (ptr);
}

char	*get_next_line(int fd)
{
	char	*ptr;
	size_t	buff_size;

	buff_size = BUFF_MIN_SIZE;
	ptr = ft_realloc(fd, buff_size);
	while (!ptr)
	{
		write (1, "\ncaracola\n", 10);
 		ptr = ft_realloc(fd, buff_size * 2);
	}
	return (ptr);
}

int	main(int argc, char *argv[])
{
	int	fd;
	char	*ptr;

	fd = open(argv[1], O_RDONLY);
	ptr = get_next_line(fd);
	print_line(ptr);
	close(fd);
}
