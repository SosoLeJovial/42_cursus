/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 22:04:48 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/16 19:34:19 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/ressources.h"

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

void	free_textures(t_data *data)
{
	if (data->images->player)
		free_player(data);
	if (data->images->walls)
		free_walls(data);
	if (data->images->conso)
		free_conso(data);
	free(data->images);
	data->images = NULL;
}

void	free_all(t_data *data)
{
	if (data->images)
		free_textures(data);
	if (data->map->map)
		ft_freemap(data->map->map, data->map->size_map);
	free_mlx(data);
	free(data);
}

void free_mlx(t_data *data)
{
    free(data->map);
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}


