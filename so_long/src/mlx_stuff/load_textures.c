/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:45:40 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/15 20:28:41 by tsofien-         ###   ########.fr       */
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
	images->player = NULL;
	images->walls = load_walls(data, &width_image, &height_image);
	images->conso = load_conso(data, &width_image, &height_image);
	if (!images->walls || !images->conso)
		return (free(images), NULL);
	return (images);
}

t_walls	*load_walls(t_data *data, int *width_image, int *height_image)
{
	t_walls	*walls;

	if (!data->mlx_ptr)
		printf("NULL MLX WTF\n");
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
