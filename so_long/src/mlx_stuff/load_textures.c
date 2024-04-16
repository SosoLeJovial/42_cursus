/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:45:40 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/17 00:40:12 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/ressources.h"

t_images	*load_textures(t_data *data)
{
	t_images	*images;
	int			width_image;
	int			height_image;

	if (!data->mlx_ptr)
    return NULL;
	width_image = TILE_WIDTH;
	height_image = TILE_HEIGHT;
	images = malloc(sizeof(t_images));
	if (!images)
		return (images);
	images->player = load_player(data, &width_image, &height_image);
	images->walls = load_walls(data, &width_image, &height_image);
	images->conso = load_conso(data, &width_image, &height_image);
	if (!images->walls || !images->conso)
		return (free(images), NULL);
	return (images);
}

t_player	*load_player(t_data *data, int *width_image, int *height_image)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->running = NULL;
	player->look_right = mlx_xpm_file_to_image(data->mlx_ptr, CHARACTER_RIGHT, width_image, height_image);
	player->look_left = mlx_xpm_file_to_image(data->mlx_ptr, CHARACTER_LEFT, width_image, height_image);
	player->look_down = mlx_xpm_file_to_image(data->mlx_ptr, CHARACTER_DOWN, width_image, height_image);
	player->look_up = mlx_xpm_file_to_image(data->mlx_ptr, CHARACTER_UP, width_image, height_image);
	return (player);
}

t_walls	*load_walls(t_data *data, int *width_image, int *height_image)
{
	t_walls	*walls;

	if (!data->mlx_ptr)
		return (NULL);
	walls = malloc(sizeof(t_walls));
	if (!walls)
		return (NULL);
	walls->corner_wall = mlx_xpm_file_to_image(data->mlx_ptr, CORNER_WALL, width_image, height_image);
	walls->side_wall = mlx_xpm_file_to_image(data->mlx_ptr, SIDE_WALL, width_image, height_image);
	walls->straight_wall = mlx_xpm_file_to_image(data->mlx_ptr, STRAIGHT_WALL, width_image, height_image);
	walls->floor = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR, width_image, height_image);
	if (!walls->corner_wall || !walls->side_wall || !walls->straight_wall || !walls->floor)
		return (free(walls), NULL);
	return (walls);
}

t_conso	*load_conso(t_data *data, int *width_image, int *height_image)
{
	t_conso	*conso;

	conso = malloc(sizeof(t_conso));
	if (!conso)
		return (NULL);
	conso->key = mlx_xpm_file_to_image(data->mlx_ptr, KEY, width_image, height_image);
	conso->door = mlx_xpm_file_to_image(data->mlx_ptr, DOOR, width_image, height_image);
	if (!conso->key || !conso->door)
		return (free(conso), NULL);
	return (conso);
}

void	free_player(t_data *data)
{
		if (data->images->player->look_right)
			mlx_destroy_image(data->mlx_ptr, data->images->player->look_right);
		if (data->images->player->look_left)
			mlx_destroy_image(data->mlx_ptr, data->images->player->look_left);
		if (data->images->player->look_up)
			mlx_destroy_image(data->mlx_ptr, data->images->player->look_up);
		if (data->images->player->look_down)
			mlx_destroy_image(data->mlx_ptr, data->images->player->look_down);
		if (data->images->player->running)
			mlx_destroy_image(data->mlx_ptr, data->images->player->running);
		free(data->images->player);
}
void	free_walls(t_data *data)
{
	if (data->images->walls)
	{
		if (data->images->walls->corner_wall)
			mlx_destroy_image(data->mlx_ptr, data->images->walls->corner_wall);
		if (data->images->walls->side_wall)
			mlx_destroy_image(data->mlx_ptr, data->images->walls->side_wall);
		if (data->images->walls->straight_wall)
			mlx_destroy_image(data->mlx_ptr, data->images->walls->straight_wall);
		if (data->images->walls->floor)
			mlx_destroy_image(data->mlx_ptr, data->images->walls->floor);
		free(data->images->walls);
	}
}
void	free_conso(t_data *data)
{
	if (data->images->conso)
	{
		if (data->images->conso->door)
			mlx_destroy_image(data->mlx_ptr, data->images->conso->door);
		if (data->images->conso->key)
			mlx_destroy_image(data->mlx_ptr, data->images->conso->key);
		free(data->images->conso);
	}
}
