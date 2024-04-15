/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 22:16:37 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/15 18:06:11 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <X11/X.h>
#include <X11/keysym.h>

t_data	init_data(t_data *data, t_data_map *map)
{
	void *mlx_ptr;

	data = malloc(sizeof(t_data));
	// if (!data)
	// 	return ;
	data->map = map;
	mlx_ptr = mlx_init();
	data->mlx_ptr = mlx_ptr;
	if (!data->mlx_ptr)
		return(free(data), *data);
	data->win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "ZEEUUUUUUUUBI");
	if (!data->win_ptr)
		return (free(mlx_ptr), *data);

	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, on_keypress, data);
	mlx_loop(data->mlx_ptr);
	return (*data);
}

int	key_hook(int keycode, t_data *vars)
{
	(void)vars;
	printf("Hello from key_hook!\n");
	printf("Keycode: %d\n", keycode);
	return (0);
}

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}
