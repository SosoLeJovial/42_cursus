/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 08:16:58 by tsofien-          #+#    #+#             */
/*   Updated: 2023/12/30 19:28:09 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	stock[BUFFER_SIZE + 1] = "\0";
	char		*line_return;

	if (fd < 0 || !fd)
		return (NULL);
	line_return = 0;
	line_return = ft_read_line(line_return, stock, fd);
	return (line_return);
}

char	*ft_read_line(char *line_read, char *stock, int fd)
{
	int		byte_read;

	if (stock)
		line_read = fill_eol(stock, 0, line_break(stock));
	byte_read = read(fd, stock, BUFFER_SIZE);
	stock[byte_read] = '\0';
	if (byte_read <= 0)
		return (NULL);
	if (line_break(stock) >= 0)
	{
		line_read = ft_strjoin(line_read, fill_str(stock, line_break(stock)));
		if (!line_read)
			return (NULL);
		stock = fill_stock_eol(stock, line_break(stock));
	}
	else
	{
		while (line_break(stock) < 0)
		{
			line_read = ft_strjoin(line_read, stock);
			if (read(fd, stock, BUFFER_SIZE) == 0)
			break ;
		}
		line_read = ft_strjoin(line_read, fill_str(stock, line_break(stock)));
		stock = fill_stock_eol(stock, line_break(stock));
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
	s = malloc(sizeof(char) * (len + 1));
	while (str[i] && i < index)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
