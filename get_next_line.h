/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estfruto <estfruto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 08:40:57 by estfruto          #+#    #+#             */
/*   Updated: 2023/11/10 10:13:58 by estfruto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h> 
# include <stddef.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*read_buffer(int fd, char *temp);
char	*full_line(char	*temp);
char	*rest_line(char *temp);
char	*free_temp(char	**str);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char	*str);
char	*ft_strjoin_mod(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *input);

#endif
