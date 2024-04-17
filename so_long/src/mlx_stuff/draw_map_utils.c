/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:57:13 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/18 00:41:38 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_size_screen(t_data *data)
{
	size_t  width;
	size_t height;

	width = 2560;
	height = 1440;
	if (data->map->map_width > width || data->map->map_height > height)
	{
		write(2 ,"Map is too big for the screen\n", 30);
		return (0);
	}
	return (1);
}
