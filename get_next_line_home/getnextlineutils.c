/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:50:12 by tsofien-          #+#    #+#             */
/*   Updated: 2023/12/01 08:11:20 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_init_buffer(char *buffer, size_t index, int fd)
{
	size_t	i;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + index + 1));
	if (!buffer)
		return (NULL);
	i = read(fd, buffer, (BUFFER_SIZE + index));
		buffer[i] = '\0';
	return (buffer);
}

char	*ft_turbo_fill_str(char *line, char *buffer, size_t \
		index, size_t size_line)
{
	size_t	i;
	size_t	j;

	line = malloc(sizeof(char) * (size_line + 1));
	i = 0;
	j = index;
	while (buffer[j] != '\n')
		line[i++] = buffer[j++];
	line[i] = '\0';
	return (line);
}

size_t	ft_turbo_find_line_break(char *buffer, size_t index)
{
	size_t		i;

	i = index;
	printf("-----------------------------------------------\n line break\n");
	printf("buffer de turbo find |%s|\n", buffer);
	while (buffer[i] != '\0')
	{
		if (i == index)
			printf("premier carac lu par turbo |%c| \n", buffer[i]);
		if (buffer[i] == '\n')
		{
			printf("turbo find a line break at : %ld = |%c|\n", i, buffer[i]);
			printf("-----------------------------------------------\n line break\n");
			return (i);
		}
		i++;
	}
	printf("-----------------------------------------------\n line break\n");
	return (0);
}

size_t	ft_strlen(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i])
		i++;
	return (i);
}