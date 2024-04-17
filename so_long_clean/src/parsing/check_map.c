/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:08:45 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/18 01:07:54 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	**ft_map_valid(char *path, t_data *data)
{
	char	**map;
	int		size;

	size = ft_line_map(path);
	if (size < 0)
		return (NULL);
	data->y_map = size;
	map = NULL;
	map = ft_mapping(path, size);
	if (!map)
		return (ft_freemap(map, size), NULL);
	if (!ft_check_char(map, size, data))
		return (ft_freemap(map, size), NULL);
	if (data->game->player != 1 || data->game->exit != 1
		|| data->game->collectibles < 1)
		return (ft_freemap(map, size), NULL);
	if (!checker_wall(map[0]) || !checker_wall(map[size - 1]))
		return (0);
	if (!check_valid_line(map, size))
		return (0);
	if (!check_line_length(map, size))
		return (0);
	return (map);
}

int	check_line_length(char **s, int size)
{
	int		length;
	int		i;
	int		j;

	i = 0;
	j = 0;
	length = 0;
	while (s[i][length])
		length++;
	while (s[i][j] && ++i < size - 2)
	{
		j = 0;
		while (s[i][j])
			j++;
		if (j != length)
			return (0);
	}
	j = 0;
	while (s[i][j])
		j++;
	if (j != length)
		return (0);
	return (1);
}

int	checker_wall(char *map)
{
	int	j;

	j = 0;
	while (map[j] && map[j] != '\0')
	{
		if (map[j] == '1' || map[j] == '\n')
			j++;
		else
			return (0);
	}
	return (1);
}

int	check_valid_line(char **map, int size)
{
	int	j;
	int	i;

	if (!map)
		return (0);
	i = 1;
	while (i < size - 1)
	{
		j = 0;
		if (map[i][0] != '1')
			return (0);
		while (map[i][j] && map[i][j] != '\0')
			j++;
		if (map[i][j - 2] != '1')
			return (0);
		i++;
	}
	return (1);
}
