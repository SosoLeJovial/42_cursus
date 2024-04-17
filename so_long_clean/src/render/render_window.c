/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 01:18:32 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/18 01:20:43 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_size_screen(t_data *data)
{
	size_t  width;
	size_t height;

	width = 2560;
	height = 1440;
	if ((data->x_map * TILE_WIDTH) > width \
	|| (data->y_map * TILE_HEIGHT) > height)
	{
		write(2 ,"Map is too big for the screen\n", 30);
		return (0);
	}
	return (1);
}
