/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 22:16:37 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/14 03:05:54 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_data	init_data(t_data *data, t_data_map *map)
{
	void *mlx_ptr;

	data = malloc(sizeof(t_data));
	if (!data)
		return (*data);
	data->map = map;
	mlx_ptr = mlx_init();
	data->mlx_ptr = mlx_ptr;
	if (!data->mlx_ptr)
		return(free(data), *data);
	data->win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "ZEEUUUUUUUUBI");
	if (!data->win_ptr)
		return (free(mlx_ptr), *data);
	while(1);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	mlx_hook(data->win_ptr, 2, 1L<<0, close, &data);
	mlx_loop(data->mlx_ptr);
	return (*data);
}
