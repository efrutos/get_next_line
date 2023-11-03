/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estfruto <estfruto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 08:56:12 by estfruto          #+#    #+#             */
/*   Updated: 2023/11/02 16:47:34 by estfruto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*buffer;
	int		i;
	int		j;

	buffer = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!buffer)
		return (NULL);
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
		free(s1);
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

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int	i;

	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	return (dst);
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
