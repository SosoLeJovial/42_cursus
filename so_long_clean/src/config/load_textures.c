/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 00:47:16 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/18 03:00:45 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_load_textures(t_data *d)
{
	int width;
	int height;

	width = TILE_WIDTH;
	height = TILE_HEIGHT;
	d->img->wall = mlx_xpm_file_to_image(d->mlx_ptr, STRAIGHT_WALL, \
		&width, &height);
	d->img->floor = mlx_xpm_file_to_image(d->mlx_ptr, FLOOR, \
		&width, &height);
	d->img->exit = mlx_xpm_file_to_image(d->mlx_ptr, DOOR, \
		&width, &height);
	d->img->conso = mlx_xpm_file_to_image(d->mlx_ptr, KEY, \
		&width, &height);
	d->img->up = mlx_xpm_file_to_image(d->mlx_ptr, CHARACTER_UP, \
		&width, &height);
	d->img->down = mlx_xpm_file_to_image(d->mlx_ptr, CHARACTER_DOWN, \
		&width, &height);
	d->img->left = mlx_xpm_file_to_image(d->mlx_ptr, CHARACTER_LEFT, \
		&width, &height);
	d->img->right = mlx_xpm_file_to_image(d->mlx_ptr, CHARACTER_RIGHT, \
		&width, &height);
	if (!d->img->wall || !d->img->floor || !d->img->exit || !d->img->conso \
		|| !d->img->up || !d->img->down || !d->img->left || !d->img->right)
		return (0);
	return (1);
}
