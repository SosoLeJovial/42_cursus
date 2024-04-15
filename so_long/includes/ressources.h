/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ressources.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:50:11 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/15 20:13:13 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESSOURCES_H
# define RESSOURCES_H
# define TILE_WIDTH 32
# define TILE_HEIGHT 32
# define WIDTH 800
# define HEIGHT 600
# define CORNER_WALL "src/assets/walls/CornerWall.xpm"
# define FLOOR "src/assets/walls/Floor.xpm"
# define SIDE_WALL "src/assets/walls/SideWall.xpm"
# define STRAIGHT_WALL "src/assets/walls/StraightWall.xpm"
# define DOOR "src/assets/consumable/Door.xpm"
# define KEY "src/assets/consumable/Key.xpm"

typedef struct walls
{
	void	*corner_wall;
	void	*side_wall;
	void	*straight_wall;
	void	*floor;
} t_walls;

typedef struct conso
{
	void	*door;
	void	*key;
} t_conso;

typedef struct player
{
	void	*look_right;
	void	*look_left;
	void	*look_up;
	void	*look_down;
	void	*running;
} t_player;

typedef struct images
{
	t_walls		*walls;
	t_conso		*conso;
	t_player	*player;

} t_images;

t_images	*load_textures(t_data *data);
t_walls		*load_walls(t_data *data, int *width_image, int *height_image);
t_conso		*load_conso(t_data *data, int *width_image, int *height_image);
#endif
