/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:33:01 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/17 22:47:06 by tsofien-         ###   ########.fr       */
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

char	**ft_mapping(char *path, int line_map)
{
	char	**map;
	char	*line;
	int		fd;
	int		i;

	if (!(ft_map_init(&map, line_map)))
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = -1;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n' && line[1] == '\0')
		{
			free(line);
			return (ft_freemap(map, ++i), NULL);
		}
		else
			map[++i] = line;
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}
