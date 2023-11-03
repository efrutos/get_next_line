/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estfruto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:57:32 by estfruto          #+#    #+#             */
/*   Updated: 2023/11/02 17:41:04 by estfruto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
/*
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 15
#endif
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;
	size_t	i;

	buffer = malloc(count * size);
	if (!buffer)
		return (NULL);
	else
	{
		i = 0;
		while (i < count)
		{
			((unsigned char *)buffer)[i] = '\0';
			i++;
		}
		return (buffer);
	}
}

/*
 * Function to update temp
*/
char	*rest_line(char *temp)
{
	char	*buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i])
		return (free(temp), NULL);
	buffer = (char *) malloc(ft_strlen(temp) - i);
	if (!buffer)
		return (free(temp), NULL);
	i++;
	while (temp[i])
		buffer[j++] = temp[i++];
	buffer[j] = '\0';
	free(temp);
	return (buffer);
}

/*
 * Function to obtain the new_line
*/
char	*full_line(char	*temp)
{
	char	*line;
	size_t	line_len;

	line_len = 0;
	while (temp[line_len] && temp[line_len] != '\n')
		line_len++;
	if (!temp[line_len])
		return (ft_strdup(temp));
	line_len = line_len + 1;
	line = (char *)ft_calloc(line_len + 1, sizeof(char));
	if (!line)
		return (NULL);
	line = ft_memmove(line, temp, line_len);
	if (!line)
		free (line);
	return (line);
}

/*
 * Funtion to read an opened file. It uses read() to read  
*/
char	*read_buffer(int fd, char *temp)
{
	char	*buffer;
	ssize_t	rbytes;

	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	rbytes = 1;
	while (!ft_strchr(temp, '\n') && rbytes > 0)
	{
		rbytes = read(fd, buffer, BUFFER_SIZE);
		if (rbytes < 0)
			return (free(buffer), free(temp), NULL);
		if (rbytes == 0)
			return (free(buffer), temp);
		buffer[rbytes] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	free(buffer);
	return (temp);
}

/*
 * Takes an opened file descriptor and returns a new line
*/
char	*get_next_line(int fd)
{
	static char	*temp[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(temp[fd]), temp[fd] = NULL, NULL);
	if ((temp[fd] && !ft_strchr(temp[fd], '\n')) || !temp[fd])
		temp[fd] = read_buffer(fd, temp[fd]);
	if (!temp[fd])
		return (NULL);
	line = full_line(temp[fd]);
	temp[fd] = rest_line(temp[fd]);
	if (temp[fd] && !temp[fd][0])
	{
		free(temp[fd]);
		temp[fd] = NULL;
	}
	return (line);
}

/*
 * Main para testar 
*/
/*
void leaks(void)
{
	system("leaks -q a.out");
}

int	main(void)
{
	int 	fd;
	char	*new_line;

	atexit(leaks);

	// Open file to obtain fd
	fd = open("file.txt", O_RDONLY);
	new_line = get_next_line(fd);
	free(new_line);
	new_line = get_next_line(fd);
	free(new_line);
	new_line = get_next_line(fd);
	free(new_line);
	
	// Cerramos el fd
	close(fd);
	return (0);
}*/
