/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estfruto <estfruto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 08:40:57 by estfruto          #+#    #+#             */
/*   Updated: 2023/11/02 16:44:32 by estfruto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h> 
# include <stddef.h>
# include <fcntl.h>

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
