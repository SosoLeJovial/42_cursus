/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:58:27 by tsofien-          #+#    #+#             */
/*   Updated: 2024/02/01 21:49:35 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = "\0";
	char		*line_final;
	ssize_t		reader;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reader = 1;
	line_final = NULL;
	if (!(buffer[0] == '\0'))
		line_final = ft_save(buffer, line_final);
	while (!ft_strchr(buffer, '\n') && reader != 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
			return (free(line_final), NULL);
		buffer[reader] = '\0';
        if (reader == 0)
            return (no_nl(line_final));
		line_final = ft_save(buffer, line_final);
	}
	if (ft_strchr(buffer, '\n'))
		ft_strcpy(buffer, ft_strchr(buffer, '\n') + 1);
	return (line_final);
}

char	*ft_save(char *buffer, char *line_final)
{
	char	*line;

	if (!buffer)
		return (NULL);
	if (!ft_strchr(buffer, '\n'))
		return (ft_strjoin(line_final, buffer));
	line = ft_line_break(buffer);
	line_final = ft_strjoin(line_final, line);
	free(line);
	return (line_final);
}

char	*ft_line_break(char *buffer)
{
	char 	*new_line;
	int		i;
	int		len;

	i = 0;
	while (buffer && buffer[i])
	{
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	new_line = ft_calloc((i + 2), sizeof(char));
	if (!new_line)
		return (NULL);
	len = i + 1;
	i = 0;
	while (i < len)
	{
		new_line[i] = buffer[i];
		i++;
	}
    new_line[i] = '\0';
	return (new_line);
}

char	*no_nl(char *line_final)
{
	if (!line_final)
		return (NULL);
	return (line_final);
}
int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("1char.txt", O_RDONLY);
	i = 0;
	while (i < 2)
	{
		line = get_next_line(fd);
		printf("line %d = %s\n %p\n", i, line, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
