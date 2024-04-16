/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:30:17 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/16 18:35:08 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// hook pour update la position du player
static int	check_valid_move(t_data *data, int x, int y);

int	pos_player(t_data *data, int keysym)
{
	int	x;
	int	y;

	x = data->map->player_x;
	y = data->map->player_y;
	if (keysym == KEY_W)
		if (check_valid_move(data, x, y - 1))
			data->map->player_y--;
	if (keysym == KEY_Q)
		if (check_valid_move(data, x - 1, y) && x > 0)
			data->map->player_x--;
	if (keysym == KEY_S)
		if (check_valid_move(data, x, y + 1) && y < (int)data->map->map_height)
			data->map->player_y++;
	if (keysym == KEY_D)
		if (check_valid_move(data, x + 1, y) && x < (int)data->map->map_width)
			data->map->player_x++;
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
		data->map->consumable_count--;
	return (1);
}
