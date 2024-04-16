/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:55:43 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/16 03:52:39 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

struct	data;
struct	data_map;
struct	images;
struct	walls;
struct	player;
struct	conso;

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

typedef struct data_map
{
	char	**map;
	size_t	size_map;
	size_t	consumable_count;
	size_t	exit_count;
	size_t	player_count;
	size_t	player_x;
	size_t	player_y;
	size_t	map_width;
	size_t	map_height;
} t_data_map;

/**
 * Main MLX handle, carries important data in regards to the program.
 * @param mlx_ptr MLX pointer
 * @param win_ptr MLX window pointer
 * @param textures MLX image pointers
 * @param map Map pointer (contains map details - preferably kept on the stack)
 */
typedef struct data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			map_width;
	int			map_height;
	int			should_exit;
	int			movement;
	t_data_map	*map;
	t_images	*images;
}	t_data;
#endif