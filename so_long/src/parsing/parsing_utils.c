/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:03:25 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/13 19:57:45 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_map_init(char ***map, int size)
{
	if (!size)
		return (0);
	*map = malloc(sizeof(char *) * (size + 1));
	if (!(*map))
		return (0);
	return (1);
}

void	*ft_freemap(char **map, int i)
{
	if (map)
	{
		while (--i != -1)
			free(map[i]);
		free(map);
	}
	return (NULL);
}

int	ft_line_map(char *path)
{
	int		line_number;
	int		fd;
	char	*line;

	line_number = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while(line)
	{
		if (!(line[0] == '\n'))
			line_number++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (line_number);
}
