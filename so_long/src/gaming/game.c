/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 02:13:06 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/16 19:47:51 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	start_game(t_data *data)
{
	data->movement = 0;
	mlx_loop_hook(data->win_ptr, &draw_map, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, key_press, data);
	mlx_loop(data->mlx_ptr);
}

int key_press(t_data *data, int keysym)
{
	printf("ça look");
	if (keysym == ESC)
	{
		free_all(data);
		exit(0);
	}
	// if (keysym == KEY_W)
	// if (keysym == KEY_W)
	// if (keysym == KEY_W)
	// if (keysym == KEY_W)
	return (0);
}
