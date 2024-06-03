/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estfruto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:58:28 by estfruto          #+#    #+#             */
/*   Updated: 2023/12/05 17:24:00 by estfruto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;
	size_t	i;

	buffer = malloc(count * size);
	if (!buffer)
	{
		return (NULL);
	}
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

size_t	ft_strlen(const char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

char	*ft_strjoin_mod(char *s1, char *s2)
{
	char	*buffer;
	int		i;
	int		j;

	buffer = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!buffer)
		return (free_temp (&s1));
	i = 0;
	while (s1 && s1[i])
	{
		buffer[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		buffer[i++] = s2[j++];
	buffer[i] = '\0';
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	return (buffer);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		else
			i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strdup(char *s1)
{
	char	*buffer;
	int		i;

	i = 0;
	buffer = (char *)malloc(ft_strlen(s1) + 1);
	if (!buffer)
		return (NULL);
	while (s1[i])
	{
		buffer[i] = s1[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
