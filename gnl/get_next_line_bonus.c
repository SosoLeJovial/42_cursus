/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:58:27 by tsofien-          #+#    #+#             */
/*   Updated: 2024/02/07 12:05:08 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1] = {{0}};
	char		*line_final;
	ssize_t		reader;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	reader = 1;
	line_final = NULL;
	if (!(buffer[fd][0] == '\0'))
		line_final = ft_save(buffer[fd], line_final);
	while (!ft_strchr(buffer[fd], '\n') && reader != 0)
	{
		reader = read(fd, buffer[fd], BUFFER_SIZE);
		if (reader == -1)
			return (free(line_final), NULL);
		buffer[fd][reader] = '\0';
		if (reader == 0)
			return (line_final);
		line_final = ft_save(buffer[fd], line_final);
	}
	if (ft_strchr(buffer[fd], '\n'))
		ft_strlcpy(buffer[fd], ft_strchr(buffer[fd], '\n') + 1, \
		ft_strlen(ft_strchr(buffer[fd], '\n')));
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
	char	*new_line;
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1)
		return (NULL);
	if (!s2)
		return (free(s1), NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	while (s1 && s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[c] && s2[c] != '\0')
		str[i++] = s2[c++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		i;

// 	fd = open("1char.txt", O_RDONLY);
// 	i = 0;
// 	while (i < 2)
// 	{
// 		line = get_next_line(fd);
// 		printf("line %d = %s\n %p\n", i, line, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }