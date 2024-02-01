/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:58:27 by tsofien-          #+#    #+#             */
/*   Updated: 2024/02/01 12:25:32 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = "\0";
	char		*line_final;
	ssize_t		reader;

	if (fd < 0 || !fd)
		return (NULL);
	reader = 1;
	line_final = NULL;
	if (ft_strlen(buffer) > 0)
		line_final = ft_strjoin(line_final, buffer);
	while (!ft_strchr(buffer, '\n') && reader != 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
			return (NULL);
		buffer[reader] = '\0';
		line_final = ft_save(buffer, line_final);
	}
	if (ft_strchr(buffer, '\n'))
		ft_strcpy(buffer, ft_strchr(buffer, '\n') + 1);
	return (line_final);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("bible.txt", O_RDONLY);
	i = 0;
	while (i < 5)
	{
		line = get_next_line(fd);
		printf("line %d = %s\n", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
