/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estfruto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:57:56 by estfruto          #+#    #+#             */
/*   Updated: 2023/11/02 17:45:59 by estfruto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

# include <stdlib.h>
# include <unistd.h> 
# include <stddef.h>
# include <fcntl.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*read_buffer(int fd, char *temp);
char	*full_line(char	*temp);
char	*rest_line(char *temp);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char	*str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
void	*ft_memmove(void *dst, const void *src, size_t n);
char	*ft_strdup(char *input);

#endif
