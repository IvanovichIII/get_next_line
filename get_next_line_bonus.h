/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:15:13 by igomez-s          #+#    #+#             */
/*   Updated: 2024/03/31 18:22:52 by igomez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t num, size_t size);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_joinfreefile(char *buffer, char *buff);
char	*ft_nextline(char *buff);
char	*ft_line(char *buff);
char	*ft_read_file(int fd, char *file);
char	*get_next_line(int fd);

#endif
