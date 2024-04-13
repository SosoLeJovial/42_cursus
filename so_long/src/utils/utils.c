/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:03:41 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/13 19:51:15 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void free_data(t_data *data)
{
	if (data->mlx_ptr)
		free(data->mlx_ptr);
	if (data->win_ptr)
		free(data->win_ptr);
	if (data->textures)
		free(data->textures);
	if (data->map)
		free(data->map);
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->map = NULL;
	free(data);
}

void	display_error(int fd, char *msg)
{
	write(fd, msg, ft_strlen(msg));
}