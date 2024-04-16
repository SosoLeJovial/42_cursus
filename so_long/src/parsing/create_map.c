/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 22:00:51 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/16 00:16:58 by tsofien-         ###   ########.fr       */
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

t_data_map *init_struct_map(char **new_map, int size)
{
	t_data_map	*new;

	if (!new_map)
		return (0);
	new = malloc(sizeof(t_data_map));
	if (!new)
		return (0);
	new->map = new_map;
	new->size_map = size;
	new->consumable_count = 0;
	new->exit_count = 0;
	new->player_count = 0;
	new->player_x = 0;
	new->player_y = 0;
	if (new_map)
		new->map_width = get_map_width(new_map) * TILE_WIDTH;
	if (new_map)
		new->map_height = get_map_height(new_map, new->size_map) * TILE_HEIGHT;
	return (new);
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
	if (fd < 0 )
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
