/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ressources.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:50:11 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/16 00:59:17 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESSOURCES_H
# define RESSOURCES_H
# define TILE_WIDTH 16
# define TILE_HEIGHT 16
# define CORNER_WALL "src/assets/walls/CornerWall.xpm"
# define FLOOR "src/assets/walls/Floor.xpm"
# define SIDE_WALL "src/assets/walls/SideWall.xpm"
# define STRAIGHT_WALL "src/assets/walls/StraightWall.xpm"
# define DOOR "src/assets/consumable/Door.xpm"
# define KEY "src/assets/consumable/Key.xpm"
# include "ressources.h"

t_images	*load_textures(t_data *data);
t_walls		*load_walls(t_data *data, int *width_image, int *height_image);
t_conso		*load_conso(t_data *data, int *width_image, int *height_image);
void		free_player(t_data *data);
void		free_walls(t_data *data);
void		free_conso(t_data *data);
void		free_textures(t_data *data);
#endif
