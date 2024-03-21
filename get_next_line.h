/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 01:30:06 by ivan              #+#    #+#             */
/*   Updated: 2024/03/21 21:14:17 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>

char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t num, size_t size);
int		ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_joinfreefile(char *buffer, char *buff);
char	*ft_nextline(char *buff);
char	*ft_line(char *buff);
char	*ft_read_file(int fd, char *file);
char	*get_next_line(int fd);
