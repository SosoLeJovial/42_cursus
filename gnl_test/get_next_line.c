/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:58:27 by tsofien-          #+#    #+#             */
/*   Updated: 2023/12/30 21:36:39 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	saved_buffer[BUFFER_SIZE + 1] = "\0";
	char		*line_final;
	// ssize_t		reader;


	if (fd < 0 || !fd)
		return (NULL);
	if (saved_buffer)
		return (saved_buffer);
	else
		line_final = 0;
	return (line_final);
}

int	main(void)
{
	char	*gnl;
	int		fd;

	fd = open("text.md", O_RDWR);
	gnl = get_next_line(fd);
	printf("%s", gnl);
	gnl = get_next_line(fd);
	printf("%s", gnl);
	gnl = get_next_line(fd);
	printf("%s", gnl);
	free(gnl);
	close(fd);
	return (0);
}