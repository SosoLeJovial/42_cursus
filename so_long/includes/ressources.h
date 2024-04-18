/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ressources.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:50:11 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/18 02:40:32 by tsofien-         ###   ########.fr       */
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
# define CHARACTER_UP "src/assets/character/character_up.xpm"
# define CHARACTER_DOWN "src/assets/character/character_down.xpm"
# define CHARACTER_LEFT "src/assets/character/character_left.xpm"
# define CHARACTER_RIGHT "src/assets/character/character_right.xpm"
# include "ressources.h"

t_images	*load_textures(t_data *data);
t_walls		*load_walls(t_data *data, int *width_image, int *height_image);
t_conso		*load_conso(t_data *data, int *width_image, int *height_image);
t_player	*load_player(t_data *data, int *width_image, int *height_image);
void		free_player(t_data *data);
void		free_walls(t_data *data);
void		free_conso(t_data *data);
void		free_textures(t_data *data);
#endif
