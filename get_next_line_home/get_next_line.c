/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 08:16:58 by tsofien-          #+#    #+#             */
/*   Updated: 2023/12/15 05:08:49 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	stock[BUFFER_SIZE + 1] = "\0";
	char		*line_return;

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line_return = ft_calloc(1,1);
	line_return = ft_read_line(line_return, stock, fd);
	return (line_return);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	n;

	ptr = (char *) malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	n = nmemb * size;
	ptr[n] = '\0';
	while (n--)
		*ptr++ = 0;
	return (ptr);
}

char	*ft_read_line(char *line_read, char *stock, int fd)
{
	int		byte_read;
	char	*line;

	line = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	byte_read = read(fd, line, BUFFER_SIZE);
	line[BUFFER_SIZE] = '\0';
	if (byte_read > BUFFER_SIZE || byte_read < 0)
		return (NULL);
	if (line_break(line) >= 0)
	{
		stock = ft_strjoin(stock, fill_eol(line, line_break(line)));
		if (!stock)
			return (NULL);
		line_read = fill_str(line, line_break(line));
	}
	else
	{
		while (line_break(line) < 0)
		{
			stock = line;
			line_read = ft_strjoin(line_read, stock);
			read(fd, line, BUFFER_SIZE);
		}
		stock = ft_strjoin(stock, fill_eol(line, line_break(line)));
		line_read = ft_strjoin(line_read, stock);
	}
	return (line_read);
}

char	*fill_str(char *str, size_t index)
{
	char	*s;
	size_t	i;
	size_t	len;

	i = 0;
	len = (size_t)ft_strlen(str) - index;
	s = calloc(sizeof(char), len + 1);
	while (str[i] && i < index)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
