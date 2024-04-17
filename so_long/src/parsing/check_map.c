/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:13:22 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/17 01:44:42 by tsofien-         ###   ########.fr       */
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
	{
		*error = 1;
		return (0);
	}
	if (!ft_check_char(map, line_map))
	{
		*error = 1; 
		return (display_error(2, "Error\n"), ft_freemap(map, line_map));
	}
	if (*error == 0)	
		if (checker_path(path, line_map))
		{
			display_error(2, "Error\n");
			return (ft_freemap(map, line_map));
		}
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
