/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:03:25 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/16 01:00:27 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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

int find_player_position(t_data_map *map)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < map->size_map)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				map->player_x = j;
				map->player_y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void *count_necessary_elements(t_data_map *maps,int size, int *error)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = -1;
		while (maps->map[i][++j])
		{
			if (maps->map[i][j] == 'P')
				maps->player_count += 1;
			if (maps->map[i][j] == 'E')
				maps->exit_count += 1;
			if (maps->map[i][j] == 'C')
				maps->consumable_count += 1;
		}
		i++;
	}
	if (maps->player_count !=  1 || maps->exit_count != 1)
		*error = 1;
	if  (maps->consumable_count < 1)
		*error = 1;
	if (!find_player_position(maps))
		*error = 1;
	return (NULL);
}

size_t get_map_width(char **map)
{
	if (!map)
		return (0);
	return (ft_strlen(map[0]) - 1);
}

size_t get_map_height(char **map, size_t size)
{
	size_t i;

	if (!map)
		return (0);
	i = 0;
	while (i < size - 1)
		i++;
	return (i + 1);
}
