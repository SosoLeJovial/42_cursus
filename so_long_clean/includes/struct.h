/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:55:43 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/18 02:00:26 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# define TILE_WIDTH 16
# define TILE_HEIGHT 16
# define CORNER_WALL "src/assets/sprites/CornerWall.xpm"
# define FLOOR "src/assets/sprites/Floor.xpm"
# define SIDE_WALL "src/assets/sprites/SideWall.xpm"
# define STRAIGHT_WALL "src/assets/sprites/StraightWall.xpm"
# define DOOR "src/assets/sprites/Door.xpm"
# define KEY "src/assets/sprites/Key.xpm"
# define CHARACTER_UP "src/assets/sprites/character_up.xpm"
# define CHARACTER_DOWN "src/assets/sprites/character_down.xpm"
# define CHARACTER_LEFT "src/assets/sprites/character_left.xpm"
# define CHARACTER_RIGHT "src/assets/sprites/character_right.xpm"

struct	s_data;
struct	s_img;
struct	s_game;

typedef struct s_game
{
	size_t	player;
	size_t	exit;
	size_t	collectibles;
	size_t	player_y;
	size_t	player_x;
	size_t	exit_y;
	size_t	exit_x;
	size_t	movement;
	int		should_exit;
}	t_game;

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*conso;
	void	*exit;
	void	*up;
	void	*down;
	void	*left;
	void	*right;
}	t_img;

typedef struct s_data
{
	char		**map;
	void		*mlx_ptr;
	void		*win_ptr;
	size_t		x_map;
	size_t		y_map;
	t_game		*game;
	t_img		*img;
}	t_data;
#endif