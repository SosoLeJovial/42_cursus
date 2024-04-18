/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 02:13:06 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/18 03:06:08 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int render_exit(t_data *data)
{
    static int 	exit_rendered;
    size_t		y; 
    size_t		x;
	
	exit_rendered = 0;
	y = data->game->exit_y;
	x = data->game->exit_x;
    if (data->game->collectibles == 0 && !exit_rendered)
    {
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->exit, x * TILE_WIDTH, y * TILE_HEIGHT);
        exit_rendered = 1;
    }
    return (0);
}

int win_bg(t_data *data)
{
	if (data->game->player_x == data->game->exit_x && data->game->player_y == data->game->exit_y && data->game->collectibles == 0)
		return (1);
	return (0);
}
