/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estfruto <estfruto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 08:56:36 by estfruto          #+#    #+#             */
/*   Updated: 2023/11/29 15:28:12 by estfruto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * Function to free reserved memory for temp variable
*/
char	*free_temp(char	**str)
{
	free (*str);
	*str = NULL;
	return (NULL);
}

/*
 * Function to update temp once full_line has been obtained
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
		return (free_temp (&temp));
	buffer = (char *) malloc(ft_strlen(temp) - i);
	if (!buffer)
		return (free_temp (&temp));
	i++;
	while (temp[i])
		buffer[j++] = temp[i++];
	buffer[j] = '\0';
	free (temp);
	temp = NULL;
	return (buffer);
}

/*
 *Function to obtain a complete full line
*/
char	*full_line(char	*temp)
{
	char	*line;
	size_t	line_len;
	size_t	i;

	line_len = 0;
	while (temp[line_len] && temp[line_len] != '\n')
		line_len++;
	if (!temp[line_len])
		return (ft_strdup(temp));
	line_len = line_len + 1;
	line = (char *)ft_calloc(line_len + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < line_len)
	{
		line[i] = temp[i];
		i++;
	}
	if (!line)
		return (NULL);
	return (line);
}

/*
 * Funtion to read a file previously opened in main function. 
 * It uses read() to read  
*/
char	*read_buffer(int fd, char *temp)
{
	char	*buffer;
	ssize_t	rbytes;

	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (free_temp (&temp));
	rbytes = 1;
	while (!ft_strchr(temp, '\n') && rbytes > 0)
	{
		rbytes = read(fd, buffer, BUFFER_SIZE);
		if (rbytes < 0)
		{
			free(buffer);
			return (free_temp (&temp));
		}
		if (rbytes == 0)
		{
			free(buffer);
			return (temp);
		}
		buffer[rbytes] = '\0';
		temp = ft_strjoin_mod(temp, buffer);
	}
	free (buffer);
	return (temp);
}

/*
 * Takes an opened file descriptor and returns a new line
*/
char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free_temp (&temp));
	if ((temp && !ft_strchr(temp, '\n')) || !temp)
		temp = read_buffer(fd, temp);
	if (!temp)
		return (NULL);
	line = full_line(temp);
	if (!line)
		return (free_temp (&temp));
	temp = rest_line(temp);
	if (temp && !temp[0])
	{
		free (temp);
		temp = NULL;
	}
	return (line);
}
