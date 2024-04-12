/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:37:05 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/12 19:21:12 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void checker_path(int *error, char *path, int size)
{
	t_data_map		*cpy;
	size_t 			i;

	cpy = init_struct_map(ft_map_valid(path, error), size);
	if (!cpy)
		*error = 1;
	expand_virus(cpy, error);
	if (*error != 0)
	{
		i = 0;
		while (i < cpy->size_map)
			printf("%s", cpy->map[i++]);
	}
	ft_freemap(cpy->map, cpy->size_map);
	free(cpy);
}

void	expand_virus(t_data_map *maps, int *error)
{
	int	x;
	int	y;
	int size;
	int		valid;


	x = maps->player_x;
	y = maps->player_y;
	size = maps->size_map;
	maps->map[x][y] = 'V';
	valid = contamination(&maps, x, y, size);
	if (!valid)
	{
		*error = 1;
		perror("Error, map is not playable !\n");
	}
}

int	contamination(t_data_map **s, int x, int y, int size)
{
	if (x < 0 || y < 0 || x >= size || y >= size)
		return (0);
	if ((*s)->map[x][y] == 'C')
		(*s)->consumable_count--;
	if ((*s)->map[x][y] == 'E')
		(*s)->exit_count--;
	if ((*s)->exit_count == 0 && (*s)->consumable_count == 0)
		return (1);
	if ((*s)->map[x][y] == '0')
	{
		(*s)->map[x][y] = 'V';
		contamination(s, x - 1, y, size);
		contamination(s, x + 1, y, size);
		contamination(s, x, y - 1, size);
		contamination(s, x, y + 1, size);
	}
	return (0);
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
