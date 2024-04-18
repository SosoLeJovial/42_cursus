/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 02:13:06 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/18 03:05:54 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape || data->game->should_exit == 1)
		close_game(data);
	if (keysym == KEY_W || keysym == KEY_Q || keysym == KEY_S || keysym == KEY_D)
		pos_player(data, keysym);
	if (win_bg(data))
	{
		write(1, "You won !\n", 10);
		close_game(data);
	}
	return (0);
}

int	close_game(t_data *data)
{
	free_data(data);
	exit(0);
	return (0);
}

int	check_valid_move(t_data *data, int x, int y)
{
	if (data->map[y][x] == '1')
		return (0);
	if (data->map[y][x] == 'E')
		if (data->game->collectibles == 0)
			return (1);
	if (data->map[y][x] == 'C')
	{
		data->map[y][x] = '0';
		data->game->collectibles--;
	}
	data->game->movement++;
	write(1, "Moves: ", 7);
	ft_putnbr_fd(data->game->movement, 1);
	write(1, "\n", 1);
	return (1);
}

void render_player(t_data *data, int x, int y, int keysym)
{
	data->game->player_x = x;
	data->game->player_y = y;
	if (keysym == KEY_W)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->up, x * TILE_WIDTH, y * TILE_HEIGHT);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->wall, x * TILE_WIDTH, (y + 1) * TILE_HEIGHT);
	}
	if (keysym == KEY_Q)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->left, x * TILE_WIDTH, y * TILE_HEIGHT);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->floor, (x + 1) * TILE_WIDTH, y * TILE_HEIGHT);
	}
	if (keysym == KEY_S)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->down, x * TILE_WIDTH, y * TILE_HEIGHT);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->floor, x * TILE_WIDTH, (y - 1) * TILE_HEIGHT);
	}
	if (keysym == KEY_D)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->right, x * TILE_WIDTH, y * TILE_HEIGHT);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->floor, (x - 1) * TILE_WIDTH, y * TILE_HEIGHT);
	}
}