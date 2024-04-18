/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:59:33 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/18 03:08:49 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_data(t_data *data)
{
	if (data)
	{
		if (data->game)
			free(data->game);
		if (data->img)
			free_img(data);
		if (data->map)
			ft_freemap(data->map, data->y_map);
		if (data->mlx_ptr)
			free_mlx(data);
		free(data);
	}
}

void	*ft_freemap(char **map, int i)
{
	if (map)
	{
		while (--i != -1)
			free(map[i]);
		free(map);
	}
	return (NULL);
}

void	free_img(t_data *d)
{
	if (d->img->wall)
		mlx_destroy_image(d->mlx_ptr, d->img->wall);
	if (d->img->floor)
		mlx_destroy_image(d->mlx_ptr, d->img->floor);
	if (d->img->exit)
		mlx_destroy_image(d->mlx_ptr, d->img->exit);
	if (d->img->conso)
		mlx_destroy_image(d->mlx_ptr, d->img->conso);
	if (d->img->up)
		mlx_destroy_image(d->mlx_ptr, d->img->up);
	if (d->img->down)
		mlx_destroy_image(d->mlx_ptr, d->img->down);
	if (d->img->left)
		mlx_destroy_image(d->mlx_ptr, d->img->left);
	if (d->img->right)
		mlx_destroy_image(d->mlx_ptr, d->img->right);
	free(d->img);
}

void free_mlx(t_data *data)
{
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}
