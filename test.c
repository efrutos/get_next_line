/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estfruto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:26:20 by estfruto          #+#    #+#             */
/*   Updated: 2023/12/01 19:14:59 by estfruto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int		fd;
	char	*new_line;

//	fd = 1;

//	fd = open("./test_gnl/1s_One_line.txt", O_RDONLY);
	fd = open("./test_gnl/2Lines_with_jumps.txt", O_RDONLY);
//	fd = open("./test_gnl/3Lines_with_jumps_too.txt", O_RDONLY);
//	fd = open("./test_gnl/5Jumps.txt", O_RDONLY);
//	fd = open("./test_gnl/The_lord_of_the_rings.txt", O_RDONLY);
	while (1)
	{
		new_line = get_next_line(fd);
		if (!new_line)
			break;
		printf("%s", new_line);
		free(new_line);		
	}
	close(fd);
	return (0);
}
