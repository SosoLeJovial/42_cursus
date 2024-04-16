/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 02:13:06 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/17 01:11:44 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int handle_input(int keysym, t_data *data);
static void find_exit(t_data *data, size_t *x, size_t *y);
static int win_bg(t_data *data);



void	start_game(t_data *data)
{
	data->movement = 0;
	data->should_exit = 0;
	draw_map(data);
	mlx_key_hook(data->win_ptr, handle_input, data);
	mlx_hook(data->win_ptr, 17, 0, close_game, data);
	mlx_loop_hook(data->mlx_ptr, render_exit, data);
	mlx_loop(data->mlx_ptr);
}
int render_exit(t_data *data)
{
    static int exit_rendered = 0;
    size_t x = 0, y = 0;

    if (data->map->consumable_count == 0 && !exit_rendered)
    {
        find_exit(data, &x, &y);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->images->conso->door, x * TILE_WIDTH, y * TILE_HEIGHT);
        exit_rendered = 1;
    }
    return (0);
}
int handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape || data->should_exit == 1)
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

static int win_bg(t_data *data)
{
	size_t exit_x = 0;
	size_t exit_y = 0;

	find_exit(data, &exit_x, &exit_y);
	if (data->map->player_x == exit_x && data->map->player_y == exit_y && data->map->consumable_count == 0)
		return (1);
	return (0);
}

int close_game(t_data *data)
{
	free_all(data);
	exit(0);
	return (0);
}

static void find_exit(t_data *data, size_t *x, size_t *y) 
{
    size_t local_x = 0;
    size_t local_y = 0;

    while (local_y < data->map->size_map)
    {
        while (local_x < ft_strlen(data->map->map[local_y]))
        {
            if (data->map->map[local_y][local_x] == 'E') {
                *x = local_x;
                *y = local_y;
                return;
            }
            local_x++;
        }
        local_x = 0;
        local_y++;
    }
}
