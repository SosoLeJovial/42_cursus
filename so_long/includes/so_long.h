/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:26:54 by tsofien-          #+#    #+#             */
/*   Updated: 2024/04/14 02:51:07 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h> // a retirer !!
# include <math.h>
# include "../libft/libft.h"
# include "../minilib/mlx.h"
# define SOLONGHPATH "../../includes/so_long.h"
# define WIDTH 1024
# define HEIGHT 1024

typedef struct data_map
{
	char	**map;
	size_t	size_map;
	size_t	consumable_count;
	size_t	exit_count;
	size_t	player_count;
	size_t	player_x;
	size_t	player_y;
} t_data_map;

t_data_map	*init_struct_map(char **new_map, int size);
void		*count_necessary_elements(t_data_map *maps,int size, int *error);


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
	void		*textures[5];
	t_data_map	*map;
}	t_data;

/*Handling Window*/
t_data		init_data(t_data *data, t_data_map *map);


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
void	free_data(t_data *data);
void	display_error(int fd, char *msg);
#endif