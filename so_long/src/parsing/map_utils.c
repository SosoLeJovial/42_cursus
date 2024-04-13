/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:37:05 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/13 03:31:05 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int checker_path(char *path, int size)
{
	t_data_map		*cpy;
	int 			error;

	error = 0;
	cpy = init_struct_map(ft_map_valid(path, &error), size);
	if (!cpy)
		return (1);
	count_necessary_elements(cpy, size, &error);
	expand_virus(cpy, &error);
	ft_freemap(cpy->map, cpy->size_map);
	free(cpy);
	return (error);
}

void	expand_virus(t_data_map *maps, int *error)
{
	int	x;
	int	y;
	int		valid;


	x = player_x;
	y = player_y;
	maps->map[x][y] = 'V';
	valid = contamination(maps, x, y, maps->size_map);
	if (valid == 0)
	{
		printf("Error map not valid\n");
		*error = 1;
	}
	printf("Exit count: %ld\n, conso : %ld\n", maps->exit_count, maps->consumable_count);
}

int	contamination(t_data_map *s, int x, int y)
{
	int		virus;

	virus = 0;
	if (x < 0 || y < 0 || x >= s->size_map || y >= s->size_map)
		return (0);
	if (s->exit_count == 0 && s->consumable_count == 0)
		return (1);
	if (s->map[x][y] == 'C')
		s->consumable_count--;
	if (s->map[x][y] == 'E')
		s->exit_count--;
	if (s->map[x][y] != '1' || s->map[x][y] != 'V')
	{

		s->map[x][y] = 'V';
		if (contamination(s, x + 1, y) == 0)
			return (0);
		if (contamination(s, x - 1, y) == 0)
			return (0);
		if (contamination(s, x, y + 1) == 0)
			return (0);
		if (contamination(s, x, y - 1) == 0)
			return (0);
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
