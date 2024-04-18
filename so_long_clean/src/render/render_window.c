/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 01:18:32 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/18 02:56:40 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	draw_map(t_data *data)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < data->y_map)
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				render_image(data, data->img->wall, x, y);
			if (data->map[y][x] == '0')
				render_image(data, data->img->floor, x, y);
			if (data->map[y][x] == 'C')
				render_image(data, data->img->conso, x, y);
			if (data->map[y][x] == 'E')
				render_image(data, data->img->floor, x, y);
			if (data->map[y][x] == 'P')
				render_image(data, data->img->down, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

int	pos_player(t_data *data, int keysym)
{
	int	x;
	int	y;

	x = data->game->player_x;
	y = data->game->player_y;
	if (keysym == KEY_W)
		if (check_valid_move(data, x, y - 1))
			render_player(data, x, y - 1, keysym);
	if (keysym == KEY_Q)
		if (check_valid_move(data, x - 1, y))
			render_player(data, x - 1, y, keysym);
	if (keysym == KEY_S)
		if (check_valid_move(data, x, y + 1))
			render_player(data, x, y + 1, keysym);
	if (keysym == KEY_D)
		if (check_valid_move(data, x + 1, y))
			render_player(data, x + 1, y, keysym);
	return (0);
}

void	start_game(t_data *data)
{
	draw_map(data);
	mlx_key_hook(data->win_ptr, handle_input, data);
	mlx_hook(data->win_ptr, 17, 0, close_game, data);
	mlx_loop_hook(data->mlx_ptr, render_exit, data);
	mlx_loop(data->mlx_ptr);
}

void	render_image(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, \
	x * TILE_WIDTH, y * TILE_HEIGHT);
}

int	check_size_screen(t_data *data)
{
	size_t	width;
	size_t	height;

	width = 2560;
	height = 1440;
	if ((data->x_map * TILE_WIDTH) > width \
	|| (data->y_map * TILE_HEIGHT) > height)
	{
		write(2, "Map is too big for the screen\n", 30);
		return (0);
	}
	return (1);
}
