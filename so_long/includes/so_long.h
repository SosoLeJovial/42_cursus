/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:26:54 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/17 01:00:15 by tsofien-         ###   ########.fr       */
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
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include "struct.h"
# include "ressources.h"

t_data_map	*init_struct_map(char **new_map, int size);
void		*count_necessary_elements(t_data_map *maps,int size, int *error);

/*Handling Window*/
t_data		*init_data(t_data *data, t_data_map *map);
size_t		get_map_height(char **map, size_t size);
size_t 		get_map_width(char **map);
int			check_size_screen(t_data *data);
void		draw_map(t_data *data);

/* Gaming */
void	start_game(t_data *data);

/* Hooks */
int			pos_player(t_data *data, int keysym);
int			close_game(t_data *data);
int			render_exit(t_data *data);




/*Parsing*/
char	**ft_map_valid(char *path, int *error);
int		ft_check_char(char **s, int line_map);
int		ft_map_empty(char *path);
int		ft_line_map(char *path);
char	**ft_mapping(char *path, int line_map);
int		ft_map_init(char ***map, int size);
void	*ft_freemap(char **map, int i);
int		checker_wall(char *map);
int		check_valid_line(char **map, int size);
int		check_line_length(char **s, int size);
int		contamination(t_data_map *s, int x, int y);
void	expand_virus(t_data_map *maps, int *error);
int 	checker_path(char *path, int size);
int		find_player_position(t_data_map *map);

/*Utils*/
char	*get_next_line(int fd);
char	*ft_save(char *buffer, char *line_final);
char	*ft_line_break(char *buffer);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	ft_bzero_gnl(void *s, size_t n);
void	*ft_calloc_gnl(size_t nmemb, size_t size);
char	*ft_strchr_gnl(char *s, char c);
size_t	ft_strlcpy_gnl(char *dst, char *src, size_t dstsize);
size_t	ft_strlen_gnl(char *str);
void	display_error(int fd, char *msg);
void	free_all(t_data *data);
void	free_mlx(t_data *data);
#endif