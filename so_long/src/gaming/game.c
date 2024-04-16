/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 02:13:06 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/16 02:15:26 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	start_game(t_data *data)
{
	draw_map(data);
	mlx_key_hook(data->win_ptr, on_destroy, &data);
	mlx_loop(data->mlx_ptr);
}
