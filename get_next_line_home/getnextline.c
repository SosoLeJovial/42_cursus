/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:50:08 by tsofien-          #+#    #+#             */
/*   Updated: 2023/12/01 08:12:46 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*line;
	size_t			size_line;
	static size_t	index;

	index = 0;
	line = NULL;
	buffer = NULL;
	buffer = ft_init_buffer(buffer, index, fd);
	size_line = ft_turbo_find_line_break(buffer, index);
	printf("index %ld\n", index);
	// while (size_line == 0)
	// {
	// 	index += BUFFER_SIZE;
	// 	free(buffer);
	// 	buffer = ft_init_buffer(buffer, index, fd);
	// 	size_line = ft_turbo_find_line_break(buffer, index);
	// }
	printf("size_line : |%ld|\n", size_line);
	line = ft_turbo_fill_str(line, buffer, index, size_line);
	index += BUFFER_SIZE - size_line;
	free(buffer);
	return (line);
}

int	main(void)
{
	int		fd;

	fd = open("text.md", O_RDONLY);
	get_next_line(fd);
	printf("\n\n\n");
	get_next_line(fd);
	printf("\n\n\n");
	get_next_line(fd);
	printf("\n\n\n");
	get_next_line(fd);
	printf("\n\n\n");
	get_next_line(fd);
	close(fd);
	return (0);
}
