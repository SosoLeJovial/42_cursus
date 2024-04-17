/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 22:16:37 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/17 19:51:35 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/ressources.h"

t_data	*init_data(t_data *data, t_data_map *map)
{
	void		*mlx_ptr;

	data = malloc(sizeof(t_data));
	if (!data)
		return (data);
	data->map = map;
	data->images = NULL;
	data->win_ptr = NULL;
	data->should_exit = 0;
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return(data);
	data->mlx_ptr = mlx_ptr;
	if (!data->mlx_ptr)
		return(data);
	data->images = load_textures(data);
	if (!data->images)
		return (data);
	if (!check_size_screen(data))
		return (data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map->map_width, data->map->map_height, "So_long");
	if (!data->win_ptr)
		return (data);
	return (data);
}
