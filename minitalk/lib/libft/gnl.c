/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 18:45:57 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/17 15:12:32 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

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
	while (!ft_strchr_gnl(buffer, '\n') && reader != 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
			return (free(line_final), NULL);
		buffer[reader] = '\0';
		if (reader == 0)
			return (line_final);
		line_final = ft_save(buffer, line_final);
	}
	if (ft_strchr_gnl(buffer, '\n'))
		ft_strlcpy_gnl(buffer, ft_strchr_gnl(buffer, '\n') + 1, \
		ft_strlen_gnl(ft_strchr_gnl(buffer, '\n')));
	return (line_final);
}

char	*ft_save(char *buffer, char *line_final)
{
	char	*line;

	if (!buffer)
		return (NULL);
	if (!ft_strchr_gnl(buffer, '\n'))
		return (ft_strjoin_gnl(line_final, buffer));
	line = ft_line_break(buffer);
	line_final = ft_strjoin_gnl(line_final, line);
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
	new_line = malloc((i + 2) * sizeof(char));
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

char	*ft_strjoin_gnl(char *s1, char *s2)
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
