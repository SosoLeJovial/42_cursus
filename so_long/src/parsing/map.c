/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:13:22 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/12 19:19:48 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
		*error = 1;
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
			return (ft_freemap(map, ++i), NULL);
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
	if (fd < 0 || !fd)
		return (0);
	if (read(fd, buf, 1) == 0)
		return (close(fd), 1);
	return (close(fd), 0);
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

t_data_map *init_struct_map(char **new_map, int size)
{
	t_data_map	*new;

	if (!new_map)
	{
		perror("fail init\n");
		return (0);
	}
	new = malloc(sizeof(t_data_map));
	if (!new)
	{
		perror("fail init\n");
		return (0);
	}
	new->map = new_map;
	new->size_map = size;
	new->consumable_count = 0;
	new->exit_count = 0;
	new->player_count = 0;
	new->player_x = 0;
	new->player_y = 0;
	return (new);
}
