/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:30:17 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/17 00:52:07 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// hook pour update la position du player
static int	check_valid_move(t_data *data, int x, int y);
static void render_player(t_data *data, int x, int y, int keysym);


int	pos_player(t_data *data, int keysym)
{
	int	x;
	int	y;

	x = data->map->player_x;
	y = data->map->player_y;
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

static int	check_valid_move(t_data *data, int x, int y)
{
	if (data->map->map[y][x] == '1')
		return (0);
	if (data->map->map[y][x] == 'E')
		if (data->map->consumable_count == 0)
			return (1);
	if (data->map->map[y][x] == 'C')
	{
		data->map->map[y][x] = '0';
		data->map->consumable_count--;
	}
	data->movement++;
	write(1, "Moves: ", 7);
	ft_putnbr_fd(data->movement, 1);
	write(1, "\n", 1);
	return (1);
}

static void render_player(t_data *data, int x, int y, int keysym)
{
	data->map->player_x = x;
	data->map->player_y = y;
	if (keysym == KEY_W)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->images->player->look_up, x * TILE_WIDTH, y * TILE_HEIGHT);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->images->walls->floor, x * TILE_WIDTH, (y + 1) * TILE_HEIGHT);
	}
	if (keysym == KEY_Q)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->images->player->look_left, x * TILE_WIDTH, y * TILE_HEIGHT);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->images->walls->floor, (x + 1) * TILE_WIDTH, y * TILE_HEIGHT);
	}
	if (keysym == KEY_S)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->images->player->look_down, x * TILE_WIDTH, y * TILE_HEIGHT);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->images->walls->floor, x * TILE_WIDTH, (y - 1) * TILE_HEIGHT);
	}
	if (keysym == KEY_D)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->images->player->look_right, x * TILE_WIDTH, y * TILE_HEIGHT);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->images->walls->floor, (x - 1) * TILE_WIDTH, y * TILE_HEIGHT);
	}
}
