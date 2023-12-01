/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 08:16:58 by tsofien-          #+#    #+#             */
/*   Updated: 2023/12/01 09:45:47 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;
	size_t	index;

	index = 0;
	line = NULL;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + index + 1);
	if (read(fd, buffer, (BUFFER_SIZE + index)) == 0)
	{
		index += BUFFER_SIZE;
		get_next_line(fd);
	}
	line = buffer;
	printf("%s", buffer);
	return (line);
}

size_t	ft_line_break(char *buffer, size_t index)
{
	size_t i;

	i = index;
	while (buffer[i] != '\0')
	{
		if (buffer[i] != '\n')
			return (i);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] != '\0')
		i++;
	return (i);
}

int main(void)
{
	int fd;

	fd = open("text.md", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
}