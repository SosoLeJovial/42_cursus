/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 08:16:58 by tsofien-          #+#    #+#             */
/*   Updated: 2023/12/21 19:01:05 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	stock[BUFFER_SIZE + 1] = "\0";
	char		*line_return;

	if (fd < 0)
		return (NULL);
	line_return = 0;
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
	ptr[n - 1] = '\0';
	while (n--)
		*ptr++ = 0;
	return (ptr);
}

char	*ft_read_line(char *line_read, char *stock, int fd)
{
	int		byte_read;
	char	*line;

	line = 0;
	byte_read = read(fd, stock, BUFFER_SIZE);
	stock[byte_read] = '\0';
	if (byte_read > BUFFER_SIZE || byte_read < 0)
		return (NULL);
	if (line_break(stock) >= 0)
	{
		line = ft_strjoin(line, fill_str(stock, line_break(stock)));
		if (!line)
			return (NULL);
		line_read = line;
		stock = fill_eol(stock, line_break(stock));
	}
	else
	{
		while (line_break(stock) < 0)
		{
			line = ft_strjoin(line, stock);
			read(fd, stock, BUFFER_SIZE);
		}
		line = ft_strjoin(line, fill_str(stock, line_break(stock)));
		stock = fill_eol(stock, line_break(stock));
		line_read = line;
	}
	return (line_read);
}

char	*fill_str(char *str, size_t index)
{
	char	*s;
	size_t	i;
	size_t	len;

	if (index <= 0)
		return (NULL);
	i = 0;
	len = (size_t)ft_strlen(str) - ((size_t)ft_strlen(str) - index);
	s = calloc(sizeof(char), (len + 1));
	while (str[i] && i < index)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
