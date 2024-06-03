/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estfruto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:26:20 by estfruto          #+#    #+#             */
/*   Updated: 2023/11/30 17:03:09 by estfruto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"


void    print_new_line(char *new_line, int fd)
{
    if (new_line != NULL)
    {
        printf("fd=%d: %s", fd, new_line);
        free(new_line);
    }
	else
		return ;
}

int main(void)
{
	int		fd3;
	int		fd4;
	int		fd5;
	char	*new_line3;
	char	*new_line4;
	char	*new_line5;
	
	fd3 = open("./test_gnl/1_One_line.txt", O_RDONLY);
	fd4 = open("./test_gnl/2Lines_with_jumps.txt", O_RDONLY);
	fd5 = open("./test_gnl/3Lines_with_jumps_too.txt", O_RDONLY);
    while (1)
    {
        new_line3 = get_next_line(fd3);
        new_line4 = get_next_line(fd4);
        new_line5 = get_next_line(fd5);
        print_new_line(new_line3, fd3);
        print_new_line(new_line4, fd4);
        print_new_line(new_line5, fd5);
        if (!new_line3 && !new_line4 && !new_line5)
            break;
    }
	close(fd3);
	close(fd4);
	close(fd5);
	return (0);
}
