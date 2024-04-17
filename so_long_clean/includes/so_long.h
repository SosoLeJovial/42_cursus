/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:26:54 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/18 01:21:58 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define KEY_W 122
# define KEY_S 115
# define KEY_Q 113
# define KEY_D 100
# define ESC 65307
# define UP 65362
# define DOWN 65361
# define LEFT 99
# define RIGHT 65507

# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h> // a retirer !!
# include <math.h>
# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include "struct.h"

/* Config */
t_data	*ft_init_data(t_data *data, char *path);
t_game	*ft_init_game(t_game *game);
t_img	*ft_init_img(t_img *img);
int		ft_load_textures(t_data *d);

/* Render */
int		check_size_screen(t_data *data);

/* Parsing */
int		ft_map_init(char ***map, int size);
char	**ft_map_valid(char *path, t_data *data);
char	**ft_mapping(char *path, int line_map);
int		ft_line_map(char *path);
int 	ft_check_char(char **s, int size, t_data *d);
int		check_line_length(char **s, int size);
int		checker_wall(char *map);
int		check_valid_line(char **map, int size);

/* Flood fill*/
int		checker_path(char *path);
void	expand_virus(t_data *d, int *error);
int		contamination(t_data *s, int x, int y);

/* Utils */
int		ft_valid_ber(char *path);
void	ft_msg(int fd, char *msg);
void	free_data(t_data *data);
void	*ft_freemap(char **map, int i);
#endif