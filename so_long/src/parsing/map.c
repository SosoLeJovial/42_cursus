/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:13:22 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/08 19:56:30 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
// 0 pour un emplacement vide,
// 1 pour un mur,
// C pour un item à collecter (C pour collectible),
// E pour une sortie (E pour exit),
// P pour la position de départ du personnage.

char	**ft_map_valid(char *path, int *error)
{
	char	**map;
	int		line_map;

	line_map = ft_line_map(path);
	map = NULL;
	if (ft_map_empty(path))
		return (0);
	map = ft_mapping(path, line_map);
	if (!map)
	{
		*error = 1;
		return (0);
	}
	if (!ft_check_char(map, line_map))
		*error = 1;
	return (map);
}

char	**ft_mapping(char *path, int line_map)
{
	char	**map;
	char	*line;
	int		fd;
	int		i;

	if (!(ft_map_init(&map, line_map)))
		return(NULL);
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
			return (NULL);
		}
		else
			map[++i] = line;
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}


int	ft_map_empty(char *path)
{
	char buf[2];
	int fd;

	fd =  open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	if (read(fd, buf, 1) == 0)
		return (close(fd), 1);
	return (close(fd), 0);
}
