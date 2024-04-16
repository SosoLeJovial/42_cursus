/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 00:31:19 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/16 13:38:06 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static	void render_image(t_data *data, void *img, int x, int y);

void	draw_map(t_data *data)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < data->map->size_map)
	{
		while (data->map->map[y][x])
		{
			if (data->map->map[y][x] == '1')
				render_image(data, data->images->walls->straight_wall, x * TILE_WIDTH, y * TILE_HEIGHT);
			if (data->map->map[y][x] == '0')
				render_image(data, data->images->walls->floor, x * TILE_WIDTH, y * TILE_HEIGHT);
			if (data->map->map[y][x] == 'C')
				render_image(data, data->images->conso->key, x * TILE_WIDTH, y * TILE_HEIGHT);
			if (data->map->map[y][x] == 'E')
				render_image(data, data->images->conso->door, x * TILE_WIDTH, y * TILE_HEIGHT);
			if (data->map->map[y][x] == 'P')
				render_image(data, data->images->walls->floor, x * TILE_WIDTH, y * TILE_HEIGHT);
			x++;
		}
		x = 0;
		y++;
	}
}

static	void render_image(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, x, y);
}

