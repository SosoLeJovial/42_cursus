/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 02:13:06 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/16 03:56:45 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	start_game(t_data *data)
{
	// data->movement = 0;
	draw_map(data);
	mlx_key_hook(data->win_ptr, on_keypress, data);
	// mlx_key_hook(data->mlx_ptr, move_player, data);
	mlx_loop_hook(data->mlx_ptr, exit_hook, data);
	mlx_loop(data->mlx_ptr);
}
