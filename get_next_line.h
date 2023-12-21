/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:42:23 by yususato          #+#    #+#             */
/*   Updated: 2023/06/12 15:42:30 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <limits.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 5

# endif

char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
char	*line_next(char *buffer, char *line);
char	*output(char *buffer);
char	*unit(char *buffer, char *buf);
char	*read_file(int fd, char *buffer, int *flag);
char	*get_next_line(int fd);

#endif