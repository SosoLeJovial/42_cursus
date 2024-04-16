/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 22:04:48 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/15 23:27:24 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/ressources.h"

void free_data(t_data *data)
{
	if (data->mlx_ptr)
		free(data->mlx_ptr);
	if (data->win_ptr)
		free(data->win_ptr);
	if (data->map)
		free(data->map);
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->map = NULL;
	free(data);
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


void free_mlx(t_data *data)
{
    if (data) {
        if (data->map) {
            if (data->map->map) {
                ft_freemap(data->map->map, data->map->size_map);
                data->map->map = NULL;
            }
            free(data->map);
            data->map = NULL;
        }
        if (data->images) 
		{
            free_textures(data);
            data->images = NULL;
        }
        if (data->mlx_ptr) {
            if (data->win_ptr) {
                mlx_destroy_window(data->mlx_ptr, data->win_ptr);
                data->win_ptr = NULL;
            }
            mlx_destroy_display(data->mlx_ptr);
            free(data->mlx_ptr);
            data->mlx_ptr = NULL;
        }
    }
}
