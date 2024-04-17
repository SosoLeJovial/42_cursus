/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:35:20 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/18 01:17:17 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_data	*ft_init_data(t_data *data, char *path)
{
	t_game	game;
	t_img	img;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->x_map = 0;
	data->y_map = 0;
	data->game = ft_init_game(&game);
	if (!data->game)
		return (free_data(data), NULL);
	data->img = ft_init_img(&img);
	if (!data->img)
		return (free_data(data), NULL);
	data->map = ft_map_valid(path, data);
	if (!data->map)
		return (free_data(data), NULL);
	return (data);
}

t_game	*ft_init_game(t_game *game)
{
	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->player = 0;
	game->exit = 0;
	game->collectibles = 0;
	game->player_y = 0;
	game->player_x = 0;
	game->exit_y = 0;
	game->exit_x = 0;
	game->movement = 0;
	return (game);
}

t_img	*ft_init_img(t_img *img)
{
	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->wall = 0;
	img->floor = 0;
	img->conso = 0;
	img->exit = 0;
	img->up = 0;
	img->down = 0;
	img->left = 0;
	img->right = 0;
	return (img);
}

int	ft_init_mlx(t_data *data)
{
	void		*mlx_ptr;

	data->win_ptr = NULL;
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (free_data(data), 0);
	data->mlx_ptr = mlx_ptr;
	if (!data->mlx_ptr)
		return (free_data(data), 0);
	if (!load_textures(data))
		return (free_data(data), 0);
	if (!check_size_screen(data))
		return (free_data(data), 0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
		data->x_map, data->y_map, "So_long: t_sofien-");
	if (!data->win_ptr)
		return (free_data(data), 0);
	return (1);
}
