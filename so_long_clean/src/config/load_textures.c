/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 00:47:16 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/18 01:10:57 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_load_textures(t_data *d)
{
	d->img->wall = mlx_xpm_file_to_image(d->mlx_ptr, STRAIGHT_WALL, \
		&d->img->width, &d->img->height);
	d->img->floor = mlx_xpm_file_to_image(d->mlx_ptr, FLOOR, \
		&d->img->width, &d->img->height);
	d->img->exit = mlx_xpm_file_to_image(d->mlx_ptr, DOOR, \
		&d->img->width, &d->img->height);
	d->img->collectible = mlx_xpm_file_to_image(d->mlx_ptr, KEY, \
		&d->img->width, &d->img->height);
	d->img->up = mlx_xpm_file_to_image(d->mlx_ptr, CHARACTER_UP, \
		&d->img->width, &d->img->height);
	d->img->down = mlx_xpm_file_to_image(d->mlx_ptr, CHARACTER_DOWN, \
		&d->img->width, &d->img->height);
	d->img->left = mlx_xpm_file_to_image(d->mlx_ptr, CHARACTER_LEFT, \
		&d->img->width, &d->img->height);
	d->img->right = mlx_xpm_file_to_image(d->mlx_ptr, CHARACTER_RIGHT, \
		&d->img->width, &d->img->height);
	if (!d->img->wall || !d->img->floor || !d->img->exit || !d->img->collectible
		|| !d->img->up || !d->img->down || !d->img->left || !d->img->right)
		return (0);
	return (1);
}
